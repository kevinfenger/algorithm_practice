#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector> 

using namespace std; 


int 
binarySearch(vector<int> v, int start, int end, int key) 
{
   if (start > end) 
      return -1;  
   int middle = (start + end) / 2;
   if (v[middle] == key) 
       return middle; 
   if (key < v[middle]) { 
       return binarySearch(v,start,middle-1,key); 
   } 
   else { 
       return binarySearch(v,middle+1,end,key); 
   }
}

int 
findMaxIncreasingSubsequence(const vector<int> v) 
{ 
    vector<int> tailTable; 
    tailTable.resize(v.size());
    tailTable[0] = v[0]; 
    int length = 1; 
 
    for (int i = 1 ; i < v.size() ; i++) { 
         if (v[i] < tailTable[0]) { 
             tailTable[0] = v[i]; 
         } 
         if (v[i] > tailTable[length-1]) { 
             tailTable[length++] = v[i]; 
         }
         else {
             int index = binarySearch(tailTable, -1, length-1, v[i]); 
             if (index >= 0) 
                 tailTable[index] = v[i]; 
         } 
    }
    return length;  
}

int 
altMaxIncreasingSubsequence(vector<int> v) 
{ 
    vector<int> up; 
    int maxLength = 1; 
    up.resize(v.size()); 
    up[0] = 1; 
    for (int i = 1 ; i < v.size(); i++) {
        up[i] = 1;
        for (int j = 0; j < i; j++) { 
            if (v[i] > v[j]) { 
               up[i] = max(up[j] + 1, up[i]); 
            }
        }
        maxLength = max(maxLength, up[i]); 
    }
    return maxLength; 
}

int main() { 
    vector<int> test = { 4, 2, 3, 15, 3, 17, 0, 19, 22, 3, 56, 58, 3, 11, 14, 15, 60, 61 }; 
//    cout << test[binarySearch(test, 0, test.size()-1, 14)] << endl; 
    cout << altMaxIncreasingSubsequence(test) << endl; 
    cout << findMaxIncreasingSubsequence(test) << endl; 
}
