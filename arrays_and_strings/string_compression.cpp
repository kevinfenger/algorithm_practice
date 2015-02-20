#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
#include <sstream>  

using namespace std; 

string 
compress_string(string input) 
{ 
    size_t initial_length = input.length(); 
    char current_char = '\0';
    int how_many = 0; 
    string output_str; 
    stringstream output; 
 
    for (int i = 0; i < initial_length; i++) 
    { 
        if (!current_char || input[i] == current_char) { 
            how_many++; 
        } 
        else { 
            output << how_many << current_char; 
            how_many = 1;
        }         
        current_char = input[i]; 
    }
    output << how_many << current_char;  
    output_str = output.str(); 

    return output_str.length() >= initial_length ? input : output_str; 
}

int main() 
{ 
    cout << endl << compress_string("aabcccccaaa") << endl; 
}
