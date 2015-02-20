#include <stdio.h> 
#include <stdlib.h> 
#include <iostream> 
#include <vector> 

using namespace std; 

bool
find_if_sum_exists(vector<int> & v, int sum) 
{ 
    unsigned v_it = 0; 
    while (v_it < v.size()) { 
        int result = v[v_it]; 
        int remaining = sum - result; 
        int middle = ((v.size() - v_it) / 2) - 1; 

        if (remaining == v[middle]) 
            return true; 
        else if (remaining > v[middle]) { 
            while (middle < v.size()) { 
                if (result+v[middle] == sum) 
                    return true; 
                middle++; 
            } 
        }
        else { 
           for (int i = v_it+1 ; i < middle; i++) { 
               if (result+v[i] == sum) 
                   return true; 
               i++;
           }
        } 
        v_it++; 
    }
    return false;  
}


int main() { 
   vector<int> v; 
   v.push_back(1); 
   v.push_back(4); 
   v.push_back(5); 

   v.push_back(7); 
   v.push_back(8); 
   v.push_back(9); 

   v.push_back(10); 
   cout << find_if_sum_exists(v, 25); 
}
