#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <iostream> 
#include <algorithm> 
using namespace std; 

struct Node { 
    Node* left; 
    Node* right; 
    int value; 
    Node (int v) { 
       value = v; 
    }
};

void insertNode(Node *& n, int value) { 
    if (n == NULL) 
        n = new Node(value); 
    if (n->value < value)  
       insertNode(n->right, value); 
    else 
       insertNode(n->left, value); 
} 

int checkHeight(Node *n) {  
    if (n == NULL) 
        return 0; 
    int leftHeight = checkHeight(n->left); 
    if (leftHeight == -1) { 
        return -1; 
    }  
    int rightHeight = checkHeight(n->right); 
    if (rightHeight == -1) { 
        return -1; 
    }
    if (abs(leftHeight - rightHeight) > 1) 
       return -1; 
    else 
       return max(leftHeight, rightHeight) + 1; 
}
bool isBalanced(Node *n) { 
    if (checkHeight(n) == -1) 
        return false; 
    return true; 
}

int main() { 
    return 0; 
}
