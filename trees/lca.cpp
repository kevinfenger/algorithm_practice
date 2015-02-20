#include <stdio.h>
#include <stdlib.h>
#include <iostream> 

using namespace std; 

struct Node { 
    Node* left; 
    Node* right; 
    int value; 
    Node (int v) { 
        this->value = v; 
    } 
}; 

void insertNode(Node *& n, int value) { 
    if (n == NULL) 
        n = new Node(value); 
    else if (value < n->value) 
        insertNode(n->left, value); 
    else 
        insertNode(n->right, value); 
}

Node* 
findLCA(Node * root, int x, int y) 
{ 
    if (root == NULL) 
        return NULL; 
    if (root->value == x || root->value == y) 
        return root; 

    Node *leftAnc = findLCA(root->left, x, y); 
    Node *rightAnc = findLCA(root->right, x, y); 

    if (leftAnc && rightAnc) 
       return root; 

    return leftAnc != NULL ? leftAnc : rightAnc; 
}

int main() 
{ 
    Node* root = NULL; 
    insertNode(root, 5); 
    insertNode(root, 7); 
    insertNode(root, 3); 
    insertNode(root, 2); 
    insertNode(root, 11);
    Node* test = findLCA(root, 2, 3);  
    cout << test->value; 
}
