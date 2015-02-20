#include <stdio.h> 
#include <stdlib.h> 
#include <iostream> 

using namespace std; 

class LinkedList {
     public:  
     LinkedList(); 
     struct Node { 
         int data; 
         Node* next; 
     };
     Node* head; 
     Node* addNode(int); 
     Node* deleteNode(Node*);
     void printAllNodes(Node*);  
     void removeDupes(); 
};

LinkedList::LinkedList() { 
    this->head = NULL; 
}

LinkedList::Node* 
LinkedList::addNode(int data) {
    Node* n = new Node;
    n->data = data;
    n->next = NULL; 
    if (this->head)  
        n->next = this->head;
    this->head = n; 
}

LinkedList::Node* 
LinkedList::deleteNode(LinkedList::Node* n) {
    if (n == this->head) { 
        this->head = n->next; 
        free(n); 
    }
    Node* prev = this->head; 
    Node* node = this->head; 
    while (node) {
        if (node == n) { 
            prev->next = n->next; 
            free(n);
        } 
        prev = node; 
        node = node->next; 
    }
}

void 
LinkedList::removeDupes() { 
   Node* head = this->head; 
   if (!head->next) 
       return; 
   while (head) { 
       Node* second = head->next; 
       while (second) { 
          if (head->data == second->data) { 
              this->deleteNode(second); 
          }
          second = second->next; 
       }
       head = head->next; 
   } 
}

void 
LinkedList::printAllNodes(Node* n) {
   if (!n->next) 
       cout << n->data; 
   else {   
       printAllNodes(n->next); 
       cout << n->data; 
   } 
}

int main() { 
    LinkedList ll; 
    ll.addNode(4);
    ll.addNode(4);
    ll.addNode(5);
    ll.addNode(6);
    ll.addNode(6);
    ll.addNode(6);
    ll.addNode(6);
    ll.addNode(6);
    ll.removeDupes();  
    ll.printAllNodes(ll.head);  
}
