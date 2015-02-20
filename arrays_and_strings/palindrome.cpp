#include <stdio.h>
#include <stdlib.h> 
#include <iostream> 

using namespace std; 

string 
create_palindrome(string input) 
{ 
   if (input.empty()) 
       return ""; 
   size_t length = input.length(); 
   input.resize(input.length() * 2 - 1); 
   for (int i = 0; i < length - 1; i++) { 
        input.insert(input.length()-i, 1, input[i]); 
   }
   return input;    
}

bool
is_palindrome(string input) 
{ 
    if (input.empty()) 
        return false; 

    for (int l = 0, r = 0; l < r ; l++, r--) { 
       if (input[l] != input[r]) 
           return false; 
    }  
    return true; 
}

int main() {
/*    string palindrome = create_palindrome("Kevin");  
    cout << endl << "Kevin as a palindrome = " << palindrome << endl << "Is " << palindrome << " a valid palindrome ? " << (is_palindrome(palindrome) ? "Yes" : "No") << endl;
    cout << endl;  */ 

    string make_me_a_palindrome;
    cout << endl; 
    cout << "Enter String : ";
    cin >> make_me_a_palindrome;
    cout << "Palindrome = " << create_palindrome(make_me_a_palindrome); 
    cout << endl; 
}
