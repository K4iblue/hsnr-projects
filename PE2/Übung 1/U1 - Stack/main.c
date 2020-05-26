/*
 * Das Programm soll einen in umgekehrter polnischer Notation
 * gegebenen arithmetischen Ausdruck einlesen, mit Hilfe des Stacks
 * auswerten und das Ergebnis anzeigen.
 */
#include <stdio.h>
#include "stack.h"

int main() {
    // Stack erstellen
    stack_t *stack = createStack();

    // User Input
    char input[64];
    printf("Bitte geben sie einen Term in umgekehrter polnischer notation (UNP) ein:\n");
    fgets(input, sizeof(input), stdin);
    printf("Ihre Eingabe: %s\n", input);

    int negative = 0;

    // Schleife über die gesamte länge des Strings
    for (int i = 0; input[i] != '\n' && i < 64; i++) {

        float temp;         // Hilfsvariable, für Subtraktion und Division
        float tempPush;     // Hilfvariable für negative Zahlen

        switch (input[i]) {
            case '+':   // Addition
                push(stack, pop(stack) + pop(stack));
                break;

            case '-':   // Subtraktion
                // wenn eine Zahl direkt nach einem Minuszeichen kommt, ist es eine negative Zahl
                if (input[i+1] != ' ') {
                    negative = 1;
                } else {
                    temp = pop(stack);
                    push(stack, pop(stack) - temp);
                }
                break;

            case '/':   // Division
                temp = pop(stack);
                push(stack, pop(stack) / temp);
                break;

            case '*':   // Multiplikation
                push(stack, pop(stack)*pop(stack));
                break;

            case ' ':   // Leerzeichen
                break;

            default:
                tempPush = input[i] - '0';   //convert character into float
                if (negative) {
                    tempPush *= (-1);    //für z.b. -4 5 +
                    negative = 0;       //negative zahl auf stack pushen
                }
                push(stack, tempPush);
                break;
        }
    }

    // Ergebnis ausgeben und Stack zerstören
    printf("Ergebnis: %f\n", top(stack));
    destroyStack(stack);
    return 0;
}
