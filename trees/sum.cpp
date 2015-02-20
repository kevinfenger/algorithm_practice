#include <stdio.h>
#include <stdlib.h>
#include <iostream> 

using namespace std; 

struct Node { 
    Node* left; 
    Node* right; 
    int value; 

    Node (int v) { 
        value = v;
    }

}; 


void 
insertNode(Node *&root, int value) { 
   if (root == NULL) 
      root = new Node(value); 
   else if (value < root->value) 
      insertNode(root->left, value); 
   else 
      insertNode(root->right, value); 

}

bool
isBST(Node *n) {
    static Node* prev = NULL; 
    if (n) { 
        if (!isBST(n->left))
           return false; 
        if (prev && n->value <= prev->value)
            return false; 
        prev = n; 
        return isBST(n->right);   
    } 
    return true; 
}

int 
findSum(Node * n, int x, int y) 
{ 
    if (n == NULL) 
        return 0; 
    if (n->value < x) 
       return findSum(n->right, x, y); 
    else if (n->value > y) 
       return findSum(n->left, x, y);
      
    return findSum(n->left,x,y) + findSum(n->right,x,y) + n->value; 

}

bool
isLeaf(Node *n) { 
    if (n == NULL) 
       return false; 
    if (n->left == NULL && n->right == NULL) 
       return true;
    return false;  
}

int 
findLeftLeavesSum(Node *n) 
{ 
    int result = 0;
    if (n == NULL) 
        return 0; 
    if (isLeaf(n->left)) 
       result = n->left->value; 
    
    return result + findLeftLeavesSum(n->left) + findLeftLeavesSum(n->right);  

}

int main() { 
    Node* root = NULL;
    insertNode(root,15);  
    insertNode(root,12);  
    insertNode(root,10);  
    insertNode(root,5);  
    insertNode(root,4);  
    cout << isBST(root) << endl; 
    cout << findSum(root, 5, 15) << endl;
    cout << findLeftLeavesSum(root) << endl;
}
