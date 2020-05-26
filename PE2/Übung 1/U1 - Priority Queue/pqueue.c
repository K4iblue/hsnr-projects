/*
 * Es soll eine Datenstruktur "pqueue_t" erstellt werden, die beliebig viele
 * Zeichenketten speichern kann. Zur Internen Kapselung der Zeichenkette und
 * der Prioritätswerten, wird eine zweite Datenstruktur "pqentry_t" erstellt.
 * Die Datenstruktur muss bei Bedarf automatisch vergrößert und verkleinert
 * werden.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pqueue.h"


struct pqueue {
    pqentry_t *head;
    pqentry_t *tail;
    int entries;
};


struct pqentry {
    pqentry_t *next;
    pqentry_t *prev;
    float priority;
    char* string;
};


pqueue_t* pq_create() {
    // Speicher allokieren, Fehlerbehandlung
    pqueue_t *pq = (pqueue_t*) malloc(sizeof(pqueue_t));
    if (pq == NULL) {
        printf("Could not allocate enough memory for a Priority Queue\n");
        return NULL;
    }
    // PQ initialisieren
    pq->head = NULL;
    pq->tail = NULL;
    pq->entries = 0;
    return pq;
}


void pq_insert(pqueue_t *pq, char* value, float p) {
    //Speicher allokieren, Fehlerbehandlung
    pqentry_t *entry = (pqentry_t*) malloc(sizeof(pqentry_t));
    if (entry == NULL) {
        printf("Could not allocate enough memory for a new Entry");
        return; // Damit wir aus der Funktion springen
    }
    // Entry initialisieren, damit das einfügen einfacher ist
    entry->next = NULL;
    entry->prev = NULL;
    entry->priority = p;
    entry->string = value;

    // Falls Queue leer ist
    if (pq->entries == 0) {
        pq->head = entry;
        pq->tail = entry;
        pq->entries++;
        return;
    }

    // Wenn Element den kleinsten Prio-Wert hat -> Am Head einfügen
    if (pq->head->priority > entry->priority) {
        entry->next = pq->head;
        pq->head->prev = entry;
        pq->head = entry;
        pq->entries++;
        return;
    }
    // Wenn Element den größten oder den gleichen Prio-Wert wie Tail hat -> Am Tail einfügen
    else if (pq->tail->priority <= entry->priority) {
        entry->prev = pq->tail;
        pq->tail->next = entry;
        pq->tail = entry;
        pq->entries++;
        return;
    }
    // Falls der Prio-Wert vom Element dazwischen liegt -> dazwischen einfügen
    else {
            pqentry_t *temp = pq->head;                         // Temp Variable für Schleife
            while (temp != NULL) {
            if (temp->next->priority >= entry->priority) {      // Wenn das Element einen kleineren Prio-Wert als das Element nach "temp" hat
                entry->next = temp->next;
                entry->prev = temp;
                temp->next->prev = entry;
                temp->next = entry;
                pq->entries++;
                return;
            }
            temp = temp->next;  // Ein Element weitergehen
        }
    }
}


char* pq_extractMin(pqueue_t *pq) {

    if (pq->entries == 0) {
        printf("Queue ist leer. Kein Element wurde entfernt");
        return NULL;
    }
    char* min = pq->head->string;
    pqentry_t *cursor = pq->head;

    // Falls nur ein Element vorhanden ist
    if (pq->entries == 1) {
        pq->head = NULL;
        pq->tail = NULL;
    } else {
        pq->head = cursor->next;    // Neuen Head gesetzt
    }
    pq->entries--;

    free(cursor);
    return min;
}


void pq_decreaseKey(pqueue_t *pq, char* value, float p) {
    pq_remove(pq, value);       // Entry entfernen
    pq_insert(pq,value, p);     // und mit neuer Priorität wieder einfügen
}


void pq_remove(pqueue_t *pq, char* value) {

    pqentry_t *cursor = pq->head;
    while(cursor != NULL) {
        if (strcmp(cursor->string, value) == 0) {   // Wenn wir den richtigen String gefunden haben
            // Einziges Element in der Queue
            if (pq->entries == 1) {
                pq->head = NULL;
                pq->tail = NULL;
                pq->entries = 0;
            }
            // Head entfernen
            else if (pq->head == cursor) {
                cursor = pq->head->next;
                pq->head->next->prev = NULL;
                pq->head = cursor;
            }
            // Tail entfernen
            else if (pq->tail == cursor) {
                cursor = pq->tail->prev;
                pq->tail->prev->next = NULL;
                pq->tail = cursor;
            }
            // Mittendrin entfernen
            else {
                cursor->prev->next = cursor->next;
                cursor->next->prev = cursor->prev;
            }
            pq->entries--;
            free(cursor);
            return;
        }
        cursor = cursor->next;  // Ein Element weitergehen
    }
    printf("Error: Value ist nicht in der Queue");
}


void pq_destroy(pqueue_t *pq) {

    pqentry_t *cursor = pq->head;
    while (pq->entries != 0) {
        cursor = pq->head;
        pq->head = pq->head->next;
        pq->entries--;
        free(cursor);
    }
    free(pq);
    printf("\nDie Queue wurde Erfolgreich geloescht\n");
}

void pq_print(pqueue_t *pq) {
    pqentry_t *cursor = pq->head;
    printf("----------------------------------------------------------------\n");
    for (int i = 0; i < pq->entries; i++ ) {
        printf("Element: % d\t",i );
        printf("| Priority: %.2f\t|", cursor->priority);
        printf(" String: %s\n", cursor->string);
        cursor = cursor->next;
    }
    printf("----------------------------------------------------------------\n");
}