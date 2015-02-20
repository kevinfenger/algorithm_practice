#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 
#include <iostream> 
#include <vector> 

using namespace std; 


int 
find_greatest_contiguous_sum(vector<int> v) 
{ 
     int sum=0, max_sum=0, best_negative=INT_MIN; 
     for (auto it : v) { 
         sum += it; 
         if (sum > max_sum) { 
             max_sum = sum; 
         } 
         else if (sum < 0) { 
             if (sum > best_negative) 
                 best_negative = sum; 
             sum = 0;
         }
     }
     return max_sum > 0 ? max_sum : best_negative; 
}

int main() { 
    vector<int> test = { -8, -3, -2, -4, -10 };
    cout << find_greatest_contiguous_sum(test);  
}
