// Suchbaum Implementation in C++
#include <iostream>
#include "searchtree.h"

using namespace std;

/* Test Treiber */
int main() {

    Node *root = nullptr;

    // Baum mit Testwerten füllen
    for (int i = 0; i < 20; i++) {
        insertNode(&root, nullptr, (rand() % 100));
    }

    insertNode(&root, nullptr, 15);

    cout << "Baum Inhalt:" << endl;
    inorder(root);

    // Hier suchen wir den Wert 15 im Baum, da wir ihn zuvor selber eingehangen haben,
    // sollte er eigentlich gefunden werden
    cout << endl << "Gesucht wird der Knoten mit dem Wert: 15" << endl;  // Debug
    containsNode(&root, 15);

    cout << "Baum wird geloescht" << endl;
    destroyTree(&root);

    // Checken ob Baum gelöscht wurde
    inorder(root);

    return 0;
}

