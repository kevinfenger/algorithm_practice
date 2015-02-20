#include <stdio.h>
#include <stdlib.h> 
#include <iostream> 

using namespace std; 

bool 
is_permutation(string str1, string str2) 
{ 
    int lowers[256] = {0}; 

    if (str1.length() != str2.length()) 
        return false;
    
    for (int i = 0; i < str1.length() ; i++) 
    {
        int index = str1[i] - 'a';  
        lowers[index]++;  
    }
    for (int i = 0; i < str2.length() ; i++) 
    { 
        int index = str2[i] - 'a'; 
        lowers[index]--; 
        if (lowers[index] < 0) 
            return false;  
    }    
    return true;  
}

void permute(string input, int n) { 
    if (n == 1) { 
        cout << input << endl;
        return;  
    }
    else { 
        for (unsigned int i = 0; i < n; i++) { 
            permute(input, n-1); 
            if (n % 2 == 1) { 
                swap(input[0], input[n-1]); 
            }
            else { 
                swap(input[i], input[n-1]); 
            }
        }
    } 

}

void permutations(string input, int start, int length) {
    if (start == length - 1) {
        cout << input << endl; return;
    }

    for (unsigned int i = start; i < length; ++i) {
        swap(input[start], input[i]);
        permutations(input, start + 1, length);
        swap(input[i], input[start]);
    }
}

int main() { 
    string s1("stringtwointerested"); 
    string s2("stirngone"); 
    //cout << endl << "is Permutation ? " << (is_permutation(s1, s2) ? "Yes" : "No") << endl; 
/*    permutations("o", 0, 1);  
    permutations("og", 0, 2);  
    permutations("oge", 0, 3);  
    permutations("ogeg", 0, 4);  */ 
    permute(s1, s1.length()); 
}
