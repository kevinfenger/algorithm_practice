#include <stdio.h> 
#include <stdlib.h> 
#include <iostream> 
#include <vector> 

using namespace std; 

void
getSortedIndexes(vector<int> v) { 
    if (v.size() == 0) {  
        cout << 0; 
        return; 
    } 
    int start_sorted_index = 0, end_sorted_index = v.size()-1; 
    int end = v.size() - 1; 

    for (int i = 0; i < v.size() ; i++) { 
        if (v[i] < v[i+1]) 
            start_sorted_index++;
        else 
            break;  
    }
    if (start_sorted_index == v.size() - 1) { 
       cout << "already sorted"; 
       return; 
    }
    for (int j = end; j >= 0; j--) { 
       if (v[j] > v[j-1]) 
           end_sorted_index--;
       else 
           break;  
    }  
    if (end_sorted_index == 0) { 
       cout << "already sorted"; 
       return; 
    }
    
    int middle_min_index = start_sorted_index+1; 
    int middle_max_index = end_sorted_index-1; 
    for (int i = start_sorted_index; i <= end_sorted_index; i++) { 
        if (v[i] < v[middle_min_index]) middle_min_index = i; 
        if (v[i] > v[middle_max_index]) middle_max_index = i; 
    } 
     
    for (int i = start_sorted_index-1 ; i >= 0 ; i--) { 
        if (v[i] <= v[middle_min_index]) { 
             start_sorted_index = i + 1; 
             break; 
        } 
    } 
    for (int j = end_sorted_index ; j < v.size(); j++) { 
        if (v[j] >= v[middle_max_index]) { 
           end_sorted_index = j - 1;
           break; 
        } 
    } 
    cout << start_sorted_index << endl;
    cout << end_sorted_index << endl;
}

int main() { 
    vector<int> test = { 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19 }; 
    getSortedIndexes(test); 
}
