#include <stdio.h>
#include "pqueue.h"

#define MAX 50

// Testtreiber
int main() {

    // Testwerte
    char string1[MAX] = "Paris";
    char string2[MAX] = "Berlin";
    char string3[MAX] = "London";
    char string4[MAX] = "Tokio";
    char string5[MAX] = "New York";

    // Queue erstellen
    pqueue_t *queue = pq_create(queue);


    // Test Strings in die Queue füllen
    pq_insert(queue, string1, 10);
    pq_insert(queue, string2, 30);
    pq_insert(queue, string3, 20);
    pq_insert(queue, string4, 50);
    pq_insert(queue, string5, 40);

    printf("Queue nach dem einfuegen:\n");
    pq_print(queue);

    printf("\nDecreaseKey Test:\n");
    pq_decreaseKey(queue, string5, 5);
    pq_print(queue);

    printf("\nRemove Test:\n");
    pq_remove(queue,string3);
    pq_print(queue);

    printf("\nExtractMin Test:\n");
    pq_extractMin(queue);
    pq_print(queue);

    // Queue zerstören
    pq_destroy(queue);

    return 0;
}
