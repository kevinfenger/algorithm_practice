#include <stdio.h>
#include <stdlib.h>
#include <iostream> 

using namespace std; 

struct Node { 
    Node* left; 
    Node* right; 
    int value; 

    Node(int v) { 
       value = v; 
    } 
};

void insertNode(Node *& root, int value) { 
    if (root == NULL) { 
        root = new Node(value); 
    } 
    else if (value < root->value) { 
        insertNode(root->left, value); 
    } 
    else { 
        insertNode(root->right, value); 
    } 
    
}

void inorderPrint(Node *root) { 
    if (root != NULL) { 
       inorderPrint(root->left); 
       cout << root->value << endl; 
       inorderPrint(root->right); 
    }
}

void convertToLinkedList(Node* root) { 
  static Node* prev = NULL; 
  if (root) { 
      convertToLinkedList(root->left); 
      root->left = prev; 
      if (prev != NULL) { 
         prev->right = root; 
      }
      prev = root;
      convertToLinkedList(root->right); 
  }
}

void printList(Node *root) {
    if (root != NULL) { 
        cout << root->value << endl; 
        printList(root->right); 
    }
}

int main() {
    Node * root = NULL;  
    insertNode(root, 15);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 14);
    insertNode(root, 13);
    insertNode(root, 2);
    insertNode(root, 18);
    insertNode(root, 19);
//    inorderPrint(root); 
    convertToLinkedList(root); 
    while (root->left) { 
        root = root->left; 
    } 
    printList(root);  
} 
