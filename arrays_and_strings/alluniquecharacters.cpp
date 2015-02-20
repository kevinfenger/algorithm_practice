#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <map> 


using namespace std; 

bool is_string_unique(char* input) 
{ 
    map<char,bool>* already_found = new map<char,bool>(); 

    for (; (*input); *input++) 
    { 
        if (already_found->find(*input) != already_found->end()) 
            return false; 
        else 
            already_found->insert(pair<char,bool>(*input,true));  
    }
    return true; 
}

int main() 
{ 
//    cout << "is unique :" << is_string_unique("test") << endl; 
    is_string_unique("kfed") ? cout << "unique" << endl : cout << "not unique" << endl; 
}
