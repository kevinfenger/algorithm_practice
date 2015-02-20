#include <stdlib.h> 
#include <stdio.h>
#include <iostream> 
#include <vector> 

using namespace std; 

vector<int> 
merge_ascending_descending_vector(vector<int> & a, vector<int> & d) { 
    vector<int> result; 
    int a_it=0, d_it=d.size()-1; 

//    if (a.size() == 0 && d.size() == 0) r; 
    if (a.size() == 0) 
        return d; 
    if (d.size() == 0) 
        return a;
    
    while (a_it < a.size() && d_it > 0) { 
        if (a[a_it] < d[d_it]) { 
            result.push_back(a[a_it]); 
            a_it++; 
        }
        else { 
            result.push_back(d[d_it]); 
            d_it--; 
        } 
    }
    while (a_it < a.size()) { 
        result.push_back(a[a_it]); 
        a_it++;
    }  
    while (d_it >= 0) { 
        result.push_back(d[d_it]); 
        d_it--;
    } 
    return result; 
}

int main() { 
     vector<int> vect1;
     vect1.push_back(1); 
     vect1.push_back(2); 
     vect1.push_back(4); 
     vector<int> vect2; 
     vect2.push_back(10); 
     vect2.push_back(7); 
     vect2.push_back(3);  
     vector<int> result = merge_ascending_descending_vector(vect1, vect2); 
     for (auto it : result) { cout << it << endl; } 
}
