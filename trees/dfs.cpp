#include <stdlib.h>
#include <stdio.h> 
#include <iostream>
#include <list> 
#include <queue> 
using namespace std; 

class Node { 
    public : 
      bool visited; 
      int value; 
      list<Node*> children; 
      Node (int v) { 
         value = v;   
      }
      void addChild(Node * n) { 
          children.push_back(n); 
      }
}; 
void dfs(Node *n) { 
    if (n == NULL) return; 
    n->visited = true; 
    for (auto it : n->children) { 
        if (it->visited == false) {
            cout << it->value << " ";  
            dfs(it); 
        }
    }          
}
void bfs(Node *n) { 
    queue<Node*> q; 
    n->visited = true; 
    q.push(n); 
    while (!q.empty()) { 
        Node * cur = q.top(); 
        q.pop(); 
        for (auto it : cur->children) { 
            if (it->visited == false) { 
                it->visited = true; 
                q.push(it); 
            }
        }
    }    
}


int main() { 
    Node *root = new Node(5); 
    root->addChild(new Node(4)); 
    root->addChild(new Node(11)); 
    root->addChild(new Node(3));
    dfs(root);  
}
