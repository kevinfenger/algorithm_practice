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
       struct Node { 
           int data;
           int count; 
           map<char, Node *> children; 
        }; 
        void create_results(Node* n);
        void insert_word(string); 
        Node* root; 
    private : 
        void _create_results(map<string, string> & result, Node* n, string prefix);  
};

Trie::Trie() 
{
    this->root = new Node;  
}

void
Trie::insert_word(string str) {
    Node* n = this->root; 
    for (char c : str) {
        Node* child;  
        auto it = n->children.find(c); 
        if (it != n->children.end()) { 
            child = it->second; 
        }  
        else { 
           child = new Node; 
           n->children.insert(pair<char,Node*>(c,child)); 
        }
        child->count++;
        n = child;   
    } 
}

void 
Trie::create_results(Node* n) {
    map<string, string> result; 
    for (auto it : n->children) { 
        _create_results(result, it.second, string(1, it.first));   
    } 
    cout << endl; 
    cout << "{"; 
    for (auto it : result) { 
        cout << it.second << ": " << it.first << ","; 
    }  
    cout << "}";
    cout << endl; 
} 

void 
Trie::_create_results(map<string, string> & result, Node* n, string prefix) {
    if (n->count == 1) {
         stringstream word; 
         word << prefix; 
         while (n->children.size() > 0) { 
             auto it = n->children.begin(); 
             n = it->second; 
             word << it->first; 
         } 
         result.insert(pair<string, string>(prefix, word.str()));  
    }
    for (auto it : n->children) { 
        this->_create_results(result, it.second, prefix+it.first); 
    }  
}

int main() { 
   Trie trie; 
   trie.insert_word("zebra");
   trie.insert_word("dog");
   trie.insert_word("duck");
   trie.insert_word("dot");
   trie.create_results(trie.root);  
}
