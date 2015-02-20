#include <stdlib.h> 
#include <stdio.h> 
#include <iostream> 

using namespace std; 

bool 
is_palindrome(string str, int si, int ei) 
{ 
    for (; si < ei; si++, ei--) { 
        if (str[si] != str[ei]) 
            return false; 
    } 
    return true; 
}

string 
reverse_string(string str) 
{ 
    for (int l=0,r=str.length()-1; l < r; l++, r--) { 
        str[l] ^= str[r]; 
        str[r] ^= str[l]; 
        str[l] ^= str[r]; 
    }
    return str;  
}


string 
make_palindrome(string str) 
{ 
    int i = str.length()-1;
    for (; i >= 0; i--) { 
        if (is_palindrome(str, 0, i)) { 
            break;      
        }
    }
    if (i+1 == str.length()) { 
        return str; 
    }
    else { 
        return str.insert(0, reverse_string(str.substr(i+1,str.length()-1))); 
    }  
}


int main() { 
    string test("abbacus"); 
    cout << make_palindrome(test) << endl; 
    string test2("aacecaaa"); 
    cout << make_palindrome(test2) << endl; 
}
