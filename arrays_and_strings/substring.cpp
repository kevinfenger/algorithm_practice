#include <stdlib.h> 
#include <stdio.h> 
#include <iostream> 
#include <sstream> 

using namespace std; 

/* 
abc 
0     1 
      2
      3 
1     2 

abcd 
0     1 
      2
      3 
      4 
1     2 
      3 
2     2
a,b,c,d 
ab,abc 
bc,bcd 
cd




*/ 

void 
print_all_substrings(string input) 
{
    int current_length = 1; 
    stringstream current; 
    cout << endl; 
    cout << input;  
    for (int i = 0 ; i < input.length() ; i++) { 
        for (int j = 0 ; j < input.length() - i ; j++) { 
            cout << input.substr(i, i+j) << endl; 
        } 
    } 
}

int main() { 
   print_all_substrings("abcde"); 
}
