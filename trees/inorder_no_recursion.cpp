#include <stdlib.h> 
#include <stdio.h> 
#include <iostream> 

using namespace std; 

struct Node { 
    Node* right; 
    Node* left; 
    int value; 
    Node (int v) { 
        this->value = v; 
    } 
};

void 
insertNode(Node *& n, int value) { 
    if (n == NULL) { 
        n = new Node(value); 
    } 
    else if (value < n->value) { 
        insertNode(n->left, value); 
    } 
    else { 
        insertNode(n->right, value); 
    } 
}

int 
findSumBetween(Node * n, int x, int y) { 
   if (n == NULL) 
       return 0; 
   if (n->value < x) 
      return findSumBetween(n->right, x, y); 
   if (n->value > y) 
      return findSumBetween(n->left, x, y);

   return findSumBetween(n->left, x, y) + findSumBetween(n->right, x, y) + n->value;  
}

void 
inorderTraversalNonRecursive(Node *n, int kth) { 
   Node* current, *pred; 

   if (n == NULL) 
       return; 
   current = n; 
   while (current != NULL) { 
       if (current->left == NULL) { 
           kth--; 
           if (kth == 0)  
               cout << current->value << " ";
           current = current->right; 
       }
       else { 
          pred = current->left; 
          while (pred->right != NULL && pred->right != current) 
             pred = pred->right; 
          if (pred->right == NULL) { 
             pred->right = current; 
             current = current->left; 
          }
          else { 
              pred->right = NULL; 
              //cout << current->value << " "; 
              kth--; 
              if (kth == 0)  
                 cout << current->value << " ";
              current = current->right; 
          } 
       } 
   } 
}

void 
inorderTraversalRecursive(Node * n) { 
    if (n != NULL) { 
        inorderTraversalRecursive(n->left); 
        cout << n->value << " "; 
        inorderTraversalRecursive(n->right); 
    }
}

int main() { 
    Node* root = NULL;
    insertNode(root,15);  
    insertNode(root,12);  
    insertNode(root,10);  
    insertNode(root,5);  
    insertNode(root,4); 
    inorderTraversalRecursive(root);
    cout << endl;   
    inorderTraversalNonRecursive(root, 3);  
    cout << endl; 
}
