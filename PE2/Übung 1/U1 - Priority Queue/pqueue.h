#ifndef PE2_U1_PRIORITY_QUEUE_PQUEUE_H
#define PE2_U1_PRIORITY_QUEUE_PQUEUE_H

// Priority Queue Datenstruktur
typedef struct pqueue pqueue_t;

// Entry Datenstruktur
typedef struct pqentry pqentry_t;

// Erstellt eine neue, leere Priority Queue
pqueue_t* pq_create();

// Fügt den Wert "value" mit der Priorität "p" in die Priority Queue "pq" ein
void pq_insert(pqueue_t *pq, char *value, float p);

// Liefert den Wert aus der Priority Queue "pq" mit höchster Priorität, also mit
// kleinstem Wert der Komponente "priority" und entfernt den Eintrag aus "pq"
char* pq_extractMin(pqueue_t *pq);

// Ändert die Priorität des Wertes "value" in der Priority Queue "pq"
// auf den neuen Wert "p"
void pq_decreaseKey(pqueue_t *pq, char* value, float p);

// Löscht den Wert "value" aus der Priority Queue "pq"
void pq_remove(pqueue_t *pq, char* value);

// Zerstört die Priority Queue "pq" und gibt den belegten Speicher wieder frei
void pq_destroy(pqueue_t *pq);

// Gibt die PQ in die Konsole aus
void pq_print(pqueue_t *pq);

#endif //PE2_U1_PRIORITY_QUEUE_PQUEUE_H
