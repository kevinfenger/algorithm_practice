#include <stdlib.h> 
#include <iostream> 

using namespace std;

void 
remove_spaces(string & str) { 
    if (str.empty()) return; 
    bool found_nonspace = false; 
    string::iterator reader; 
    auto writer = str.begin();  
    
    for (reader = str.begin() ; reader != str.end() ; reader++) { 
         if (isspace(*reader)) { 
             if (found_nonspace) { 
                 *writer++ = *reader; 
             } 
             found_nonspace = false; 
             continue; 
         }
         found_nonspace = true; 
         *writer++ = *reader; 
    } 
    str.erase(writer-1,reader); 
} 
int main() {
    string test("    Hello    World    Test   ");  
    remove_spaces(test);
    cout << test;  
} 
