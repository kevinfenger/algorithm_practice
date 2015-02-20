#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector> 

using namespace std; 

int 
andSolutionExists(vector<int> v) {
    int res = -1;
 
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) { 
            if (i == j) 
               continue; 
            if (res < 0) 
               res = v[j]; 
            else 
               res &= v[j];             
        }
        if (res == v[i]) 
            return v[i]; 
        else 
            res = -1; 
    }
    return res; 
}

int main() { 
    vector<int> test = { 191411,256951,191411,191411,191411,256951,195507,191411,192435,191411,
 191411,195511,191419,191411,256947,191415,191475,195579,191415,191411,
 191483,191411,191419,191475,256947,191411,191411,191411,191419,256947,
 191411,191411,191411 }; 
    cout << andSolutionExists(test) << endl; 
}
