/* Ald Übung 1 - Selection Sort
 *
 * Ablauf des Algorithmus (Vom Übungsblatt):
 * 1. Führen die folgenden beiden Schritte für i = 0 bis N - 2 aus.
 * 2. Bestimme das Minimum a[k] aller Zahlen a[i] bis a[N - 1]
 * 3. Tausche das Minimum a[k] mit a[i]
 */

#include <stdio.h>
#include <stdlib.h>     // Für srand()
#include <windows.h>    // Für Zeitmessung

void swap (int *a, int *b);
void selectionSort(int array[], int size);

int main() {

    LONGLONG g_Frequency, g_FirstCount, g_LastCount;
    double duration;    // Gibt die Laufzeit
    int size;

    // Get array size
    printf("Wie gross soll das Array sein?\n");
    scanf("%d", &size);
    int array[size];

    // Fancy Printing
    printf("=============================================\n");
    printf("Unsorted Array:\n");
    
    // Fill array with random numbers
    for (int j = 0; size > j ; j++) {
        array[j] = rand() % 100;    // "% 100" damit wir nur kleine Zahlen bekommen
        printf("Element %d: \t %d \n", j, array[j]);
    }

    // Vor dem Aufrufe der Sortierfunktion
    QueryPerformanceFrequency((LARGE_INTEGER*)&g_Frequency);
    QueryPerformanceCounter((LARGE_INTEGER*)&g_FirstCount);

    // Run selection sort
    selectionSort(array, size);

    // nach dem Aufruf der Sortierfunktion
    QueryPerformanceCounter((LARGE_INTEGER*)&g_LastCount);
    duration = (((double)(g_LastCount-g_FirstCount))/((double)g_Frequency));

    // Fancy Printing
    printf("=============================================\n");
    printf("Sorted Array:\n");
    for (int m = 0; m < size; m++) {
        printf("Element %d: \t %d\n", m, array[m]);
    }
    printf("=============================================\n");
    // Laufzeit duration und Größe des Feldes ausgeben
    printf("Array size: %d\n", size);
    printf("Duration: %f\n", duration);

}

/* Selection Sort
 * Pseudo-code:
 * 1. Wiederhole Schritt 2 und 3 bis kein unsortieres Element mehr vorhanden ist
 * 2. Suche das kleinste unsortierte Element
 * 3. Tausche das kleinste unsortierte Element mit dem ersten Element der unsortierten Elementen
 */
void selectionSort(int array[], int n) {
    int min;

    for (int i = 0; i < n - 1; i++) {

        // Find minimum in unsorted array
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        // Swap the found element with first element
        swap(&array[min], &array[i]);
    }
}

// Simple swap function
void swap (int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}