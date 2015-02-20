#include <stdlib.h> 
#include <stdio.h> 
#include <iostream> 
#include <vector>
#include <limits.h>  

using namespace std; 

vector<int> 
merge(vector<int> & v, vector<int> & left, vector<int> & right) { 
    vector<int> result; 
    size_t left_it=0, right_it=0; 
    while (left_it < left.size() && right_it < right.size()) { 
        if (left[left_it] < right[right_it]) { 
            result.push_back(left[left_it]); 
            left_it++; 
        }
        else { 
            result.push_back(right[right_it]); 
            right_it++; 
        }
    }  
    while (left_it < left.size()) { 
        result.push_back(left[left_it]); 
        left_it++; 
    } 
    while (right_it < right.size()) { 
        result.push_back(right[right_it]); 
        right_it++; 
    } 
    v = result; 
    return v;  
}

vector<int>
merge_sort(vector<int> & v) {
    if (v.size() == 1) 
        return v; 

    auto middle = v.begin() + (v.size()/2); 
    vector<int> left(v.begin(), middle); 
    vector<int> right(middle, v.end()); 
    left = merge_sort(left); 
    right = merge_sort(right); 
    return merge(v, left, right); 
}

int main() { 
    vector<int> v; 
    v.push_back(1); 
    v.push_back(15); 
    v.push_back(10); 
    v.push_back(3); 
    v.push_back(7); 
    v.push_back(4); 
    v = merge_sort(v); 
    for (auto it : v) { 
        cout << it << endl; 
    }  
}
