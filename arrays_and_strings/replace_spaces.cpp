#include <stdio.h> 
#include <stdlib.h>
#include <iostream>

using namespace std; 

string 
replace_spaces(string input) 
{ 
    for (int i = 0; i < input.length(); i++) 
    { 
       if (isspace(input[i])) { 
           input.erase(i,1);
           input.insert(i, "%20");
           i = i+2; 
       } 
    }
    return input;  
}

int main() { 
    string escaped_string = replace_spaces("Mr John Smith"); 
    cout << endl; 
    cout << escaped_string; 
    cout << endl; 
}
