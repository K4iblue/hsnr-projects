#ifndef UNTITLED_SEARCHTREE_H
#define UNTITLED_SEARCHTREE_H

/* Datenstruktur eines Knotes des Baum */
struct Node;

/* Datenstruktur des Suchbaums */
/* Optional */
struct SearchTree;

/* Funktion wird rekursiv ausgeführt
 * Ist der Wert des Element kleiner (größer) als der Wert des Knotens,
 * führe insertNode auf den linken (rechten) Teilbaum aus, bis der
 * entsprechende Teilbaum leer ist. An dem leeren Teilbaum wird der neu
 * erzeugte Knoten mit den neuen Wert eingefügt. Ist der Wert bereits
 * vorhanden, füge ihn nicht noch einmal ein. Ist der Baum leer, wird der
 * neue Knoten der Wurzelknoten.
 * Return -1, fall der Wert bereits vorhanden ist, ansonsten 0.
 */
int insertNode(Node **n, Node *parent, int val);


/* Funktion wird rekursiv ausgeführt
 * Ist der Wert des Elements kleiner (größer) als der Wert des Knotens, suche
 * im linken (rechten) Teilbaum weiter bis das Element gefunden wurde oder der
 * Teilbaum leer ist. Ist der (Teil-)Baum leer, ist das Element nicht vorhanden.
 * Return true, wenn der Wert gefunden wurde, ansonsten false.
 */
bool containsNode(Node **n, int val);


/* Die Funktion gibt die Werte mittels Inorder-Traversierung aus
 * Funktion wird rekursiv ausgeführt, bis alle Werte durchlaufen wurden
 * Algorithmus:
 * 1. Traverse left
 * 2. Visit root node
 * 3. Traverse right
 */
void inorder (Node *n);

/* Funktion wird rekursiv ausgeführt
 * Zerstört den Baum via Postorder Traversal
 *  Algorithmus:
 * 	1. Traverse left
 * 	2. Traverse right
 * 	3. Visit Node
 */
void destroyTree(Node **n);

#endif //UNTITLED_SEARCHTREE_H
