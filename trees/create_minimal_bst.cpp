#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector> 

using namespace std; 

struct Node { 
    Node* left; 
    Node* right; 
    int value; 
    Node(int v) { 
        value = v; 
    }
};

Node* 
createMinimalBST(vector<int> v, int start, int end) { 
   if (end < start) 
       return NULL; 
   int mid = (start + end) / 2; 
   Node* n = new Node(v[mid]); 
   n->left = createMinimalBST(v, start, mid - 1); 
   n->right = createMinimalBST(v, mid + 1, end); 
   return n;    
}

int main() { 
   
}
