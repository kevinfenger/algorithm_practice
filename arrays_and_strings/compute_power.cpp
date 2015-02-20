#include <stdlib.h>
#include <iostream>  
#include <vector> 

using namespace std; 

long long
compute_power(int x, int y) { 
    vector<long long> already_computed(y+1,0); 

    already_computed[0] = 1; 
    for (int i = 1; i <= y; i++) { 
        already_computed[i] = already_computed[i-1] * x; 
    } 
    return already_computed[y]; 
}

int main() { 
    cout << compute_power(2,16) << endl; 
}
