/*
 * Implementieren Sie eine doppelt-verkettete Liste zum sortierten Speichern von INTs
 */

#include <stdio.h>
#include <stdlib.h>

// Datenstruktur eines Listenelements
typedef struct eintrag {
    int key;
    struct eintrag *p_prev;
    struct eintrag *p_next;
} eintrag_t;

// Datenstruktur mit Informationen ueber die Liste
typedef struct {
    eintrag_t *p_head;
    eintrag_t *p_tail;
    eintrag_t *p_curr;
} liste_t;

eintrag_t *create_element (int key);
void insert_element(liste_t *liste, eintrag_t *p_insert);
void print_list(liste_t *liste);
liste_t *create_list();

int main() {

    int size = 0;

    // Listen Grösse vom User abfragen
    printf("Wie gross soll die Liste sein?\n");
    scanf("%d", &size);

    // Liste erstellen
    liste_t *sortedList = create_list();

    // Liste mit zufälligen Werten füllen
    for (int i = 0; i < size; i++) {
        eintrag_t *newElement = create_element(rand() % 100);
        insert_element(sortedList, newElement);
    }

    // Liste ausgeben
    print_list(sortedList);

    return 0;
}

/* Legt den Speicher für ein Listenelement an,
 * speichert den key-Wert im Element.
 * Gibt einen Zeiger auf das neue Listenelement zurück.
 */
eintrag_t *create_element (int key) {

    eintrag_t *newElement = (eintrag_t *) malloc(sizeof(eintrag_t));
    if (newElement == NULL) {
        printf("Could not allocate enough memory for a new Element");
    }
    newElement->p_next = NULL;
    newElement->p_prev = NULL;
    newElement->key = key;

    return newElement;
}

/* Fügt ein Element sortiert in die Liste ein.
 * Zuerst wird die Position gesucht, an der das Listenelement
 * eingefügt werden soll.
 * Es sind 3 Möglichkeiten zu unterscheiden, am Anfang der Liste,
 * mitten in der Liste oder am Ende der Liste.
 * Anschließend wird das Element in die Liste eingefügt.
 */
void insert_element(liste_t *liste, eintrag_t *p_insert) {
    // Wenn die Liste leer ist, wird das neue Element zum Head und Tail
    if (liste->p_head == NULL) {
        liste->p_head = p_insert;
        liste->p_tail = p_insert;
    }
        // Wenn das neue Element einen kleineren Key als der Head hat, wird das neue Element zum neuen Head
    else if (p_insert->key < liste->p_head->key) {
        p_insert->p_next = liste->p_head;   // Neues Element zeigt auf Head
        liste->p_head->p_prev = p_insert;   // Head zeigt zurück auf das neue Element
        liste->p_head = p_insert;           // Neues Element wird zum neuen Head
    }
        // Wenn das neue Element einen größeren Key als der Tail hat, wird das neue Element zum neuen Tail
    else if (p_insert->key > liste->p_tail->key) {
        liste->p_tail->p_next = p_insert;   // Tail zeigt auf das neue Element
        p_insert->p_prev = liste->p_tail;   // Neues Element zeigt zurück auf Tail
        liste->p_tail = p_insert;           // Neues Element wird zum neuen Tail
    }
    else {
        // Platz finden wo das neue Element einsortiert werden soll
        eintrag_t *cursor = liste->p_head;   // Variable um durch die Liste zu laufen
        while (p_insert->p_next == NULL) {
            liste->p_curr = cursor;
            if (p_insert->key > cursor->key) {
                cursor = cursor->p_next;         // Cursor geht zum nächsten Element
            } else {
                p_insert->p_prev = liste->p_curr->p_prev; // Zeiger vom neuen Element auf den linken nachbarn
                p_insert->p_next = liste->p_curr;         // Zeiger vom neuen Element auf den rechten nachbarn
                liste->p_curr->p_prev->p_next = p_insert; // Zeiger auf das neue Element vom linken nachbarn
                liste->p_curr->p_prev = p_insert;         // Zeiger vom rechten nachbarn zurück auf das neue Element
            }

        }
    }
}


// Gibt alle Listen-Elemente aus
void print_list(liste_t *liste) {
    eintrag_t *cursor = liste->p_head;  // Variable um durch die Liste zu laufen
    int i = 0;
    while (cursor != NULL) {
        printf("Listen Element %d\t|| %d\n", i, cursor->key);
        cursor = cursor->p_next;
        i++;
    }
}


// Erstellt eine neue Liste mit zwei Dummy Nodes
liste_t *create_list() {
    liste_t* newList = malloc(sizeof(liste_t));
    if(newList == NULL) {
        printf("Could not allocate enough memory for a List");
        return NULL;

    } else {
        newList->p_head = NULL;
        newList->p_tail = NULL;
        newList->p_curr = NULL;
        return newList;
    }
}