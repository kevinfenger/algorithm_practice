#include <stdio.h>
#include <stdlib.h> 
#include <iostream> 

using namespace std; 

struct Node { 
    int value; 
    Node* next; 
    Node(int v) { 
        value = v; 
    }
}; 

void
insertNode(Node *&headRef, int value) 
{ 
    Node * n = new Node(value); 
    n->next = headRef; 
    headRef = n; 
}

int findSize(Node *n) { 
   int size = 0; 
   while (n) { 
      size++; 
      n = n->next; 
   }
   return size;  
}

void 
findKthFromEnd(Node * head, int k) 
{ 
    int size = findSize(head); 
    Node *ptr = head; 
    for (int i = 1; i < size - k + 1; i++) { 
        ptr = ptr->next; 
    } 
    cout <<  ptr->value << endl; 
}

void 
findKth(Node * head, int k) 
{ 
    Node *ptr = head; 
    for (int i = 1; i < k; i++) { 
       ptr = ptr->next; 
    }
    cout << ptr->value << endl; 
}

void 
swapKth(Node *& head, int k) 
{ 
    int size = findSize(head); 
    Node *backPtr = head; 
    Node *backPrev = NULL;
    for (int i = 1; i < size - k + 1; i++) { 
       backPrev = backPtr; 
       backPtr = backPtr->next; 
    }

    Node *frontPtr = head; 
    Node *frontPrev = NULL; 
    for (int i = 1; i < k; i++) { 
        frontPrev = frontPtr; 
        frontPtr = frontPtr->next; 
    }
    
    if (frontPtr == backPtr) 
        return; 
    if (frontPrev) 
       frontPrev->next = backPtr;
    if (backPrev) 
       backPrev->next = frontPtr; 

    Node *tmp = frontPtr->next; 
    frontPtr->next = backPtr->next; 
    backPtr->next = tmp; 

    if (k == 1) 
       head = backPtr; 
    if (k == size) 
       head = frontPtr;  
}

void 
printList(Node *n) {
    if (n == NULL) 
       cout << endl; 
    else {   
        cout << n->value << " "; 
        printList(n->next); 
    }
}

void 
reverse(Node *& n) { 
    Node * prev = NULL; 
    while (n) { 
       Node *temp = n->next; 
       n->next = prev;
       prev = n; 
       n = temp;        
    }
    n = prev; 
}

int main() {
   Node* head = NULL; 
   for (int i = 10 ; i >= 1 ; i--) 
       insertNode(head, i);

   printList(head);  
   findKthFromEnd(head, 4);  
   findKth(head, 4); 
   swapKth(head, 3);  
   printList(head); 
   reverse(head);  
   printList(head); 
}
