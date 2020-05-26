#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

// Testtreiber
int main() {

    heap_t *heap = createHeap();

    // User input für Heap Größe
    int size = 0;
    printf("Wie viele Elemente soll der Heap enthalten?\n");
    scanf("%d", &size);
    printf("Ihre Eingabe: %d\n\n", size);

    for (int i = 0; i < size; i++) {
        insert(heap, (rand() % 100));
    }

    // Heap ausgeben
    printf("Heap Ausgabe (Anfang): %s\n\n", toString(heap));

    printf("Kleinstes Element (Vor extractMin): %d\n", minimum(heap));
    extractMin(heap);
    printf("Kleinstes Element (nach extractMin): %d\n\n", minimum(heap));

    printf("Heap Ausgabe (Ende): %s\n", toString(heap));

    // Heap zerstören
    destroyHeap(heap);

    return 0;
}
