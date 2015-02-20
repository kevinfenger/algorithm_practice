#include <stdio.h> 
#include <stdlib.h> 
#include <iostream> 
#include <map> 

using namespace std; 

int 
atoi_mine(string input) { 
    if (input.empty()) 
        return 0; 
    int result = 0, sign = 1, i=0; 
    if (input[i] == '-') { 
       sign = -1;
       i++; 
    }
    for (; i < input.length(); i++) {
        result = result*10 + input[i] - '0'; 
    }
    return result*sign;  
}

string
reverse_string(string input) { 
    if (input.empty()) 
        return ""; 
    for (int l = 0, r=input.length()-1; l < r; l++, r--) 
    {
        char tmp = input[l];  
        input[l] = input[r]; 
        input[r] = tmp; 
    } 
    return input; 
}

string 
itoa_mine(int input) { 
    int i = 0;
    bool is_neg = false;  
    string output;
    if (input < 0) {
        input = -input;
        is_neg = true; 
    }
    while (input != 0) { 
       int rem = input % 10;
       output.resize(output.size() + 1); 
       output[i++] = (rem > 9) ? (rem-10) + 'a' : rem + '0';
       input = input / 10;  
    }
    if (is_neg) { 
       output.resize(output.size() + 1); 
       output[i++] = '-'; 
    } 
    output[i] = '\0';
    return reverse_string(output); 
}

long 
factorial(int n) { 
    if (n==0) 
       return 1; 
    return n * factorial(n-1); 
}

long 
fib(int n) { 
  int result[n]; 
  result[0] = 0; 
  result[1] = 1; 
  for (int i = 2; i < n ; i++) { 
      result[i] = result[i-2] + result[i-1];
      cout << result[i];  
  }
  return result[n-1]; 
}


int main() { 
    /*string test("kevin"); 
    string blah = reverse_string(test);
    cout << endl << blah << endl;  
    cout << endl << atoi_mine("-123") << endl;  
    cout << endl << fib(7) << endl;  
    cout << endl << factorial(4) << endl;  */
    string test = itoa_mine(-44321);  
    cout << endl << "kevin : " << test << endl;  
} 
