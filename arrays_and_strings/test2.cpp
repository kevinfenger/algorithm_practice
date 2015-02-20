#include <stdlib.h>
#include <iostream> 

using namespace std; 

void make_palindrome(string & str) { 
    size_t length = str.length(); 
    str.resize(length + length); 
    for (int l = 0, r = length + length - 2; l < r ; l++, r--) { 
        str[r] = str[l]; 
    }
}

void reverse_string(string & str) { 
    if (str.empty()) 
        return; 
    for (int l = 0, r = str.length()-1; l < r; l++, r--) { 
        str[l] ^= str[r]; 
        str[r] ^= str[l]; 
        str[l] ^= str[r]; 
    } 
}

int atoi(string str) { 
    if (str.empty()) 
        return 0; 
    int result = 0, i = 0, sign = 1; 
    if (str[i] == '-') { 
        sign = -1; 
        i++; 
    } 
    for (; i < str.length() - 1; i++) { 
        result = result*10 + str[i] + '0'; 
    } 
    return result*sign; 
}

long long fib(int n) {
    long long prev[n]; 

    prev[0] = 0; 
    prev[1] = 1; 

    for (int i = 2; i <= n; i++) { 
       prev[i] = prev[i-1] + prev[i-2]; 
    }
    return prev[n];  
}

void 
print_substrings(string str) { 
    for (int i = 0 ; i < str.length() ; i++) {  
        for (int j = 0; j < str.length()-i; j++) { 
            cout << str.substr(i, i+j) << endl;
        }
    } 
}

bool 
is_substring(string sub_str, string str) { 
    int matched_count = 0; 
    int sub_str_length = sub_str.length()-1;
    if (sub_str.length() > str.length()) 
        return false;  
    for (int i = 0 ; i < str.length() ; i++) {
        if (sub_str[matched_count] ==  str[i]) 
            matched_count++; 
        else  
            matched_count = 0;
        if (matched_count == sub_str_length)  
            return true; 
    } 
    return false; 
} 


int main() {
    string test("kevin");  
    make_palindrome(test);
    cout << test << endl; 
    string test2("testa"); 
    reverse_string(test2); 
    cout << test2 << endl;

    cout << atoi("12345") << endl;  
    cout << fib(65) << endl; 

    print_substrings("abcdef"); 

    cout << is_substring("abcd", "abcd");  
}
