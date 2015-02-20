#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <sstream> 
#include <vector>  
#include <map>

using namespace std; 

// DAMP, LIKE 
// OUTPUT - DAMP -> LAMP -> LIMP -> LIME -> LIKE 

class Trie {
     public :
     Trie();  
     struct Node {
         int data;  
         map<char, Node*> children; 
     };
     void insertWord(string str);
     string createNewWordList(string, string);  
     string findWord(string);  
     Node* root; 
};

Trie::Trie() { 
    this->root = new Node; 
}

void
Trie::insertWord(string str) { 
    Node * root = this->root; 
    for (char c : str) { 
       Node* child; 
       auto it = root->children.find(c); 
       if (it != root->children.end()) { 
           child = it->second; 
       } 
       else { 
           child = new Node;
           root->children.insert(pair<char,Node*>(c, child));  
       }
       root = child;  
    }
}

string
Trie::findWord(string str) { 
    Node * root = this->root; 
    stringstream ss; 
    for (char c : str) { 
        auto it = root->children.find(c); 
        if (it == root->children.end()) { 
            return ""; 
        } 
        ss << it->first;
        root = it->second;  
    }
    return ss.str();  
}

string
Trie::createNewWordList(string start, string end) {
     stringstream ss; 
     ss << start << " -> "; 
     vector<int> skippedIndexes; 
     for (int s = 0; s < start.length(); s++) { 
         for (int t = 0; t < end.length(); t++) { 
             char tmp = start[s]; 
             start[s] = end[t]; 
             string newWord = this->findWord(start); 
             if (!newWord.empty()) { 
                 end.erase(t, 1); 
                 ss << newWord << " -> "; 
                 break;  
             } 
             start[s] = tmp;
             if (t == end.length()-1) 
                 skippedIndexes.push_back(s);  
         }
    }
    if (!skippedIndexes.empty() && !end.empty()) { 
        if (skippedIndexes.size() > end.length()) { 
            ss.clear(); 
            ss << "won't work";
            return ss.str();  
        }
        while (!skippedIndexes.empty()) { 
            int index = skippedIndexes.back(); 
            for (int u = 0; u < end.length(); u++) { 
                start[index] = end[u]; 
                string newWord = this->findWord(start); 
                if (!newWord.empty()) { 
                    end.erase(u, 1); 
                    ss << newWord << " -> ";
                    skippedIndexes.pop_back(); 
                    break;  
                } 
                if (u == end.length()-1) { 
                    ss.clear(); 
                    ss << "won't work"; 
                    return ss.str();  
                } 
            } 
        } 
    }
    return ss.str();   
}

int main() { 
    Trie t; 
    t.insertWord("DAMP"); 
    t.insertWord("LAMP"); 
    t.insertWord("LIMP"); 
    t.insertWord("LIME"); 
    t.insertWord("LIKE");
    cout << t.createNewWordList("DAMP", "LIKE"); 
    cout << endl;  
} 
