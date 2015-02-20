#include <stdlib.h>
#include <stdio.h>
#include <iostream> 

using namespace std; 

class LinkedList { 
     public: 
     LinkedList(); 
     struct Node { 
        int data; 
        Node* next; 
     }; 
     void insertNode(int data); 
     void partition(int x);
     void printAllNodes(Node*);  
     Node* head;  
};

LinkedList::LinkedList() { 
    this->head = NULL; 
}

void
LinkedList::insertNode(int data) { 
    Node* n = new Node;
    n->data = data;
    n->next = NULL; 
    if (this->head)  
        n->next = this->head;
    this->head = n;
}

void
LinkedList::partition(int pivot) { 
    LinkedList tmpBefore; 
    LinkedList tmpAfter; 
    Node* n = this->head; 
    while (n) {  
       if (n->data < pivot) { 
          tmpBefore.insertNode(n->data); 
       }
       else { 
          tmpAfter.insertNode(n->data);
       } 
       n = n->next; 
    }
    n = tmpBefore.head; 
    while (n->next) { 
        n = n->next; 
    } 
    n->next = tmpAfter.head; 
    this->head = tmpBefore.head;      
}

void 
LinkedList::printAllNodes(Node* n) {
   if (!n->next) 
       cout << n->data; 
   else {   
       cout << n->data; 
       printAllNodes(n->next); 
   } 
}

int main() { 
     LinkedList ll; 
     ll.insertNode(5); 
     ll.insertNode(6); 
     ll.insertNode(7); 
     ll.insertNode(4); 
     ll.insertNode(3); 
     ll.insertNode(11); 
     ll.partition(6);
     ll.printAllNodes(ll.head);  
}
