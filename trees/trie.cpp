#include <stdio.h>
#include <stdlib.h> 
#include <iostream> 
#include <sstream>  
#include <list> 
#include <map> 
using namespace std; 

class Trie {
    public : 
    void insert_node();
    int search();  
    Trie(); 
    typedef struct Node Node_t; 
    struct Node { 
       int data;
       int count; 
       Node* children[26]; 
    }; 
    void  insert_node(string); 
    Node* get_new_node(); 
    Node* root;
    int size; 
    void create_results(Node* n);
    private : 
        void _create_results(map<string, string> & result, Node* n, string prefix);  
};

Trie::Trie() { 
    this->root = get_new_node(); 
}

Trie::Node* 
Trie::get_new_node() { 
    Node* n = NULL; 
    n = (Node*)malloc(sizeof(Node)); 
    n->data = 0;
    n->count = 1;  
    for (int i = 0; i < 26; i++) 
    { 
        n->children[i] = NULL; 
    }
    return n;  
}

void
Trie::insert_node(string str) { 
    int length = str.length(), 
        index=0, 
        level=0;

    Trie::Node* current = this->root; 

    for (level = 0; level < length; level++) { 
       index = str[level] - 'a'; 
       if (current->children[index] == NULL) { 
           current->children[index] = get_new_node();
           current->children[index]->count++;  
       }
       else { 
           current->children[index]->count++;  
       } 
       current = current->children[index];  
    }  
    current->data = level; 
    this->size++; 
}

void 
Trie::create_results(Node* n) { 
    map<string, string> result; 
    for (int i=0; i < 26; i++) {
        if (n->children[i])  
            _create_results(result, n->children[i], string(1, i + 'a')); 
    } 
} 

void 
Trie::_create_results(map<string, string> & result, Node* n, string prefix) {
    if (n->count == 1) { 
        stringstream word; 
        word << prefix;
        while (n) {  
            for (int i = 0; i < 26 ; i++) { 
                if (n->children[i]) { 
                    word << i + 'a'; 
                    n = n->children[i]; 
                    break; 
                }  
            } 
            n = NULL; 
        }
        cout << word;  
    } 
}

int main() { 
   Trie trie; 
   trie.insert_node("test");
   trie.create_results(trie.root);  
}
