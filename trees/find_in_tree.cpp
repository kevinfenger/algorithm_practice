#include <stdlib.h>
#include <stdio.h> 
#include <limits.h> 
#include <iostream> 

using namespace std; 

class Node {
    public:  
        int data; 
        Node* left;
        Node* right; 
        Node(); 
        ~Node();  
};

Node::Node() 
{ 
    this->left = NULL; 
    this->right = NULL; 
    this->data = INT_MIN;
}

Node::~Node() 
{ 
}

bool 
exists_in_tree(int data, Node* head)
{ 
    if (head == NULL) 
        return false; 
    else if (data == head->data) 
        return true; 
    else { 
        if (head->left) 
            return exists_in_tree(data, head->left);
        if (head->right) 
            return exists_in_tree(data, head->right); 
    }
}

int main() 
{ 
    Node root;
    Node left;  
    root.data = 3;
    root.left = &left;
    root.left->data = 4;
 
    exists_in_tree(4, &root) ? cout << "yes" : cout << "nope";    
}
