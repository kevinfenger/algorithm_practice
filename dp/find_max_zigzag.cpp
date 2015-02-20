#include <stdlib.h>
#include <stdio.h> 
#include <iostream>
#include <vector> 

using namespace std; 

int 
findMaxZigZag(vector<int> v) { 
    if (v.size() < 2) 
        return 1; 
    int bestResult=1;
    vector<int> up; 
    vector<int> down;
    up.resize(v.size()); 
    down.resize(v.size()); 
    up[0] = down[0] = 1; 
    for (int i = 1; i < v.size() ; i++) {
       for (int j = 0; j < i ; j++) {  
          if (v[i] > v[j]) { 
             up[i] = max(down[j] + 1, up[i]);
          }  
          if (v[i] < v[j]) { 
             down[i] = max(up[j] + 1, down[i]); 
          }
       }
       bestResult = max(bestResult, max(up[i], down[i]));  
    }
    return bestResult; 
}


int main() { 
    vector<int> test = 	{ 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 }; 
    cout << findMaxZigZag(test) << endl; 
}
