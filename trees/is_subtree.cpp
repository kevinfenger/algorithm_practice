#include <stdlib.h> 
#include <stdio.h> 
#include <iostream>

using namespace std; 

struct Node { 
	Node* left; 
	Node* right; 
	int value;
	Node(int v) { 
		value = v; 
		right = NULL; 
		left = NULL; 
	}  
}; 
void insertNode(int, Node *&nextNode); 
bool isSubTree(Node *, Node*);
bool compareTrees(Node *, Node*);  
Node* root; 
void printInOrder(Node*);
Node* binarySearch(int, Node*);  

bool 
isSubTree(Node* bigTree, Node* littleTree) { 
    if (bigTree == NULL) 
        return false; 
    
    if (bigTree->value == littleTree->value) { 
        compareTrees(bigTree, littleTree); 
    } 
    else { 
        return (isSubTree(bigTree->left, littleTree) || isSubTree(bigTree->right, littleTree)); 
    } 
}

bool
compareTrees(Node* tree1, Node* tree2) { 
    if (tree1 == NULL && tree2 == NULL) { 
        return true; 
    } 
    if (tree1 == NULL || tree2 == NULL) { 
        return false; 
    } 

    if (tree1->value != tree2->value) { 
        return false; 
    }  

    compareTrees(tree1->left, tree2->left); 
    compareTrees(tree1->right, tree2->right); 
}

 
void 
insertNode(int value, Node *&nextNode) { 
 
  /*  if (root == NULL) {
       root = new Node(value); 
       return; 
    }*/ 
    if (nextNode == NULL) { 
        Node* newNode = new Node(value);
        nextNode = newNode;
        return;  
    }  
    else if (value < nextNode->value) { 
        insertNode(value, nextNode->left); 
    }
    else { 
        insertNode(value, nextNode->right); 
    } 
}

Node* 
binarySearch(int key, Node * n) { 
    if (n == NULL) { 
        return n; 
    }   
    if (n->value == key) { 
        return n;  
    } 
    if (key < n->value) 
        binarySearch(key, n->left);
    else  
        binarySearch(key, n->right); 
} 

void 
printInOrder(Node * root) { 
    if (root == NULL) 
        return; 
    if (root->left) 
        printInOrder(root->left); 
    cout << root->value << endl; 
    if (root->right) 
        printInOrder(root->right); 
}

int main() {
     Node* root = NULL;  
     insertNode(13, root);
     insertNode(15, root);
     insertNode(5, root);
//     insertNode(8, root);
//     insertNode(1, root);
//     insertNode(13, root);
//     insertNode(17, root);
//     insertNode(25, root);
     Node* root2 = NULL;  
     insertNode(1, root2);
     insertNode(12, root2);
     insertNode(3, root2);
     printInOrder(root);
//     Node* n = binarySearch(5, root);
  //   if (n)  
    //     cout << n->value << endl;  
     cout << isSubTree(root, root2) << endl; 
}
