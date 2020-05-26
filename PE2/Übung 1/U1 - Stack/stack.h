#ifndef PE2_U1_STACK_STACK_H
#define PE2_U1_STACK_STACK_H

// Datenstruktur für Elemente auf dem Stack
typedef struct node node_t;

// Stack Datenstrucktur
typedef struct stack stack_t;

// Erzeugt einen leeren Stack
stack_t *createStack();

// Prüft, ob der Stack leer ist
char isEmpty(stack_t *s);

// Legt den Wert "value" auf den Stack
void push(stack_t *s, float value);

// Liefert das zuletzt eingefügte Element des Stacks
float top(stack_t *s);

// Entfernt das zuletzt eingefügte Element vom Stack
float pop(stack_t *s);

// Liefert den Inhalt der Fehlervariablen
char getError(stack_t *s);

// Zerstört den Stack und gibt belegten Speicherplatz frei
void destroyStack(stack_t *s);

#endif //PE2_U1_STACK_STACK_H
