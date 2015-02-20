#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std; 

int findMinOperations(vector<int> v, int k) { 
    sort(v.begin(), v.end());
    int rv = INT_MAX;
 
    for (int i = 0; i < v.size() - k + 1; i++) { 
       vector<int> results; 
       for (int j = 0; j < k; j++) 
         results.push_back(v[i+j]-j); 
       sort(results.begin(), results.end()); 
       int current = 0; 
       for (int j = 0 ; j < k; j++) 
           current += abs(results[j] - results[k/2]); 
       rv = min(rv, current); 
    }
    cout << endl; 
    return rv; 
}

int main() { 
    vector<int> test =	{-96, -53, 82, -24, 6, -75};
    cout << findMinOperations(test, 4) << endl; 
}
