#include <stdlib.h> 
#include <stdio.h>
#include <iostream> 
#include <queue> 

using namespace std; 

struct Node { 
    Node *left;
    Node *right; 
    int value; 
    Node (int v) { 
       this->value = v; 
    } 
}; 

void 
insertNode(Node *& root, int value) { 
    if (root == NULL)  
       root = new Node(value); 
    else if (value < root->value) 
       insertNode(root->left, value); 
    else 
       insertNode(root->right, value); 
}

void 
levelOrderTraversal(Node *root) { 
    queue<Node*> q; 
    q.push(root); 
    
    while (!q.empty()) { 
        Node* n = q.front();
        q.pop();  
        cout << n->value << " "; 
        if (n->left != NULL) 
           q.push(n->left); 
        if (n->right != NULL) 
           q.push(n->right); 
    }
    cout << endl; 
}

int main() { 
    Node* root = NULL;  
    insertNode(root,5);  
    insertNode(root,15);  
    insertNode(root,12);  
    insertNode(root,4); 
    insertNode(root,10);  
    levelOrderTraversal(root); 
}
