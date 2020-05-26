#include <iostream>
#include "searchtree.h"

using namespace std;

/* Datenstruktur eines Knotes des Baum */
struct Node {
    int value;
    Node *left, *right;
    Node *parent;   // Optional
};

int insertNode(Node **n, Node *parent, int val) {
    // Falls noch keine Root Node vorhanden ist
    if ((*n) == nullptr) {
        (*n) = new Node;
        (*n)->value = val;
        (*n)->left = (*n)->right = nullptr;
        (*n)->parent = parent;
        return 0;
    }
    // Falls der Wert größer ist als der des aktuellen Knotens gehen in den Rechten Teilbaum
    if(val > (*n)->value) {
        return insertNode(&(*n)->right, (*n), val);
    }
    // Falls der Wert kleiner ist als der des aktuellen Knotens gehen in den linken Teilbaum
    else if (val < (*n)->value) {
        return insertNode(&(*n)->left, (*n), val);
    }
    // Falls der Wert aber schon vorhanden ist => Fehler
    else {
        return -1;
    }
}


bool containsNode(Node **n, int val) {
    // Fehlerbehandlung, falls kein Knoten vorhanden ist
    if ((*n) == nullptr) {
        cout << "Keine Knoten im (Teil-)Baum vorhanden";
        return false;
    }
    // Falls der Wert größer ist als der des aktuellen Knotens gehen in den Rechten Teilbaum
    else if ((*n)->value > (*n)->right->value) {
        containsNode(&(*n)->right,val);
    }
    // Falls der Wert kleiner ist als der des aktuellen Knotens gehen in den linken Teilbaum
    else if ((*n)->value < (*n)->left->value){
        containsNode(&(*n)->left,val);
    }
    // Sonst wurde der Knoten gefunden
    else {
        cout << "Knoten gefunden" << endl;
    }
    return true;
}


void inorder (Node *n) {
    if (n == nullptr) {
        cout << "Baum ist leer";
        return;
    }

    if (n->left != nullptr) {
        inorder(n->left);
    }

    cout << n->value << " | ";

    if (n->right != nullptr) {
        inorder(n->right);
    }
    else {
        return;
    }
}


void destroyTree(Node **n) {
    if ((*n) == nullptr) {
        cout << "Baum ist leer" << endl;
        return;
    }

    if ((*n)->left == nullptr) {
        destroyTree(&(*n)->left);
    }

    if ((*n)->right == nullptr) {
        destroyTree(&(*n)->right);
    }

    delete (*n);
    (*n) = nullptr;

    return;
}
