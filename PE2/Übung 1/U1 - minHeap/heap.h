#ifndef PE2_U1_MINHEAP_HEAP_H
#define PE2_U1_MINHEAP_HEAP_H

// Heap Datenstruktur
typedef struct heap heap_t;

// Erzeugt einen leeren Heap
heap_t *createHeap();

// Fügt den Wert "val" in den Heap ein
char insert(heap_t *h, int val);

// Liefert das minimale Eleent des Heaps
int minimum(heap_t *h);

// Entfernt das minimale Element aus dem Heap
char extractMin(heap_t *h);

// Liefert den Inhalt der Fehlervariable des Heaps
char getError(heap_t *h);

// Liefert den Inhalt der Heaps als Zeichenkette
char *toString(heap_t *h);

// Zerstörst den Heap und gibt belegten Speicherplatz frei
void destroyHeap(heap_t *h);

// Einfache Swap function
void swap(heap_t *h, int pos1, int pos2);

// Funktion um die Heap vorrausetzung wieder herzustellen
void heapify(heap_t *h, int size, int index);

#endif //PE2_U1_MINHEAP_HEAP_H