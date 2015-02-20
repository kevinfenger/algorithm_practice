#include <vector>
#include <stdlib.h> 
#include <stdio.h> 
#include <iostream> 

using namespace std; 

int 
max_diff(vector<int> v) { 
    int min_element = v[0];
    int max_diff = v[1] - v[0];  
    for (unsigned int i = 1 ; i < v.size() ; i++) { 
        if (v[i] < min_element) { 
            min_element = v[i]; 
        } 
        if (v[i] - min_element > 0) {
           max_diff = max(max_diff, v[i] - min_element);              
        } 
    }
    return max_diff;  
}

int main() { 
    vector<int> a = { 11, 2, 3, 4, 7, 10 }; 
    cout << max_diff(a);    
}
