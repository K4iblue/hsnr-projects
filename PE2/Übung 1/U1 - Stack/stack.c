/*
 * Der Stack soll beliebig wachsen und schrumpfen können
 * Es sollen beliebig viele Floatwerte gespeichert werden können.
 * Wenn auf einem leeren Stack "top" oder "pop" ausgeführt werden
 * Soll eine Fehlervariable gesetzt werden.
 */
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

// Datenstruktur für Elemente auf dem Stack
struct node {
    float value;
    struct node *next;
};

// Stack Datenstruktur, implementiert als Lineare Liste
struct stack {
    node_t *top;
    char error;
};

// Erzeugt einen leeren Stack
stack_t *createStack() {
    // Speicher allokieren, Fehlerbehandlung
    stack_t* s= (stack_t*) malloc(sizeof(stack_t));
    if (s == NULL) {
        printf("Could not allocate enough memory for the stack");
        return NULL;
    } else {
        s->top = NULL;
        s->error = 0;
        return s;
    }
}

// Prüft, ob der Stack leer ist
char isEmpty(stack_t *s) {
    if(s->top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Legt den Wert "value" auf den Stack
void push(stack_t *s, float value) {
    // Speicher allokieren, Fehlerbehandlung
    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    if (newNode == NULL) {
        printf("Could not allocate enough memory for a new Element");
        return;
    }
    newNode->value = value;
    newNode->next = s->top;
    s->top = newNode;
}

// Liefert das zuletzt eingefügte Element des Stacks
float top(stack_t *s) {
    if (isEmpty(s) == 1 ) {
        s->error = 1;
        return 1;
    }

    return s->top->value;
}

// Entfernt das zuletzt eingefügte Element vom Stack
float pop(stack_t *s) {
    if (isEmpty(s) == 1 ) {
        s->error = 1;
        return 1;
    }
    node_t *toPop = s->top;
    float value = s->top->value;

    // setze "top" neu
    s->top = toPop->next;

    free(toPop);
    return value;
}

// Liefert den Inhalt der Fehlervariablen
char getError(stack_t *s) {
    return s->error;
}

// Zerstört den Stack und gibt belegten Speicherplatz frei
void destroyStack(stack_t *s) {
    node_t *temp = s->top;

    while ((temp = s->top) != NULL) {
        s->top = s->top->next;
        free(temp);
    }
}