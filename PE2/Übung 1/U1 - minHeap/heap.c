/*
 * Der Heap soll bei Bedarf automatisch vergrößert werden, sodass er beliebig
 * viele INT-Werte speichern kann. Wenn "minimum" auf einen leeren Heap
 * ausgeführt wird, soll eine Fehlervariable gesetzt werden.
 */

/* minHeap als Array
 * Arr[0]       Root Element
 * Arr[(i-1)/2] Returns the parent node
 * Arr[(2*i)+1] Returns the left child node
 * Arr[(2*i)+2] Returns the right child node
 */

/*  Min Heap:
 *  Parent Node is always smaller than or equal
 *  to its child nodes
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

// Heap Datenstruktur
struct heap {
    int *values;    // Zeiger auf das Heap Array
    int size;       // Wie viele Nodes aktuell im Heap sind
    int index;
    int capacity;   // Wie viele Nodes reinpassen
    char error;
};


// Erzeugt einen leeren Heap
heap_t *createHeap() {
    heap_t *h = calloc(1, sizeof(heap_t));   // Speicher allokieren

    // Fehlerbehandlung
    if (h == NULL) {
        printf("Could not allocate enough Memory for the Heap");
        return 0;
    }
    h->size = 0;
    h->index = 0;
    h->capacity = 3;    // 1 Parent node + 2 Child Nodes
    h->values = (int *) malloc(sizeof(int)*h->capacity);
    h->error = 0;

    return h;
}


// Fügt den Wert "val" in den Heap ein
char insert(heap_t *h, int val) {
    // Falls Heap leer, erstes Element einfügen
    if (h->size == 0) {
        h->values[0] = val;
        h->size++;
        return h->error;
    }

    // Falls wir nicht genug Kapazität haben, mehr Speicher allokieren
    if (h->size == h->capacity) {
        h->capacity += 3;
        h->values = (int *) realloc(h->values, h->capacity * sizeof(int));
    }

    // Element am Ende des Heaps einfügen, größe erhöhen
    h->values[h->size] = val;
    h->size++;

    // MinHeap bauen
    for (int i = h->size / 2 - 1; i >= 0; i--) {
        heapify(h, h->size, i);
    }

    // Heapify anwenden, falls Child < Parent swappen
    for (int i = h->size - 1; i >=0; i--) {
        swap(h, 0, i);
        heapify(h, i, 0);
    }

    return h->error;
}


// Liefert das kleinste Element des Heaps
int minimum(heap_t *h) {
    // Falls Heap leer, error ausgeben
    if (h->size == 0) {
        h->error = 1;
        return h->error;
    }
    return h->values[0];
}


// Entfernt das minimale Element aus dem Heap
char extractMin(heap_t *h) {
    // Falls Heap leer, error ausgeben
    if (h->size == 0) {
        h->error = 1;
        return h->error;
    }

    // Speicher verringern
    if (h->size < h->capacity / 2) {
        h->capacity -= 3;
        h->values = (int *) realloc(h->values, h->capacity * sizeof(int));
    }

    // Jedes Element wird um 1 nach links verschoben
    for (int i = 0; i < (h->size - 1); i++) {
        h->values[i] = h->values[i+1];
    }
    h->size--;

    return h->error;
}


// Liefert den Inhalt der Fehlervariable des Heaps
char getError(heap_t *h) {
    return h->error;
}


// Liefert den Inhalt der Heaps als Zeichenkette
char *toString(heap_t *h) {
    char *string = (char *) calloc(1, h->size * 4);    // *2 da im ich im Testtreiber höchstens zweistellige Zahlen habe
                                                    // *4 um für jede Zahl ',' einzufügen
    for (int i = 0; i < h->size; i++) {
        char tmp[2];    // 2, da höchstens zweistellige Zahlen

        if(i > 0) {     //add ', ' to string
            unsigned int len = strlen(string);
            string[len] = ',';
            string[len+1] = ' ';
            string[len+2] = '\0';
        }
        sprintf(tmp, "%d", h->values[i]);   // Int zu Char casten
        strcat(string, tmp);                // Int an Output anhängen
    }

    return string;
}


// Zerstörst den Heap und gibt belegten Speicherplatz frei
void destroyHeap(heap_t *h) {
    // Erst werden die Werte im Heap zerstört
    free(h->values);
    // Dann der komplette Heap
    free(h);
}


// Einfache Swap Funktion
void swap(heap_t *h, int pos1, int pos2){
    int temp = h->values[pos1];
    h->values[pos1] = h->values[pos2];
    h->values[pos2] = temp;
}

// Funktion um die Heap vorrausetzung wiederherzustellen
void heapify(heap_t *h, int size, int index) {

    // Parent Node, and Child Nodes variables
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    // Left Child ist kleiner als parent
    if (leftChild < size && h->values[leftChild] > h->values[smallest]) {
        smallest = leftChild;
    }

    // Right Child ist kleiner als parent
    if (rightChild < size && h->values[rightChild] > h->values[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(h, index, smallest);
        heapify(h, size, smallest);
    }
}
