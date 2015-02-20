#include <stack> 
#include <stdio.h>
#include <stdlib.h>
#include <iostream> 

using namespace std; 
int doCalc(string n1, string n2, string o) { 
    char c = o[0];
    int i=0, j=0; 
    if (!n1.empty()) 
        i = stoi(n1); 
    if (!n2.empty()) 
        j = stoi(n2); 

    switch (c) { 
        case '+' :
            return (i + j);              
        case '-' :
            return (i - j); 
        case '*' : 
            return (i * j); 
        case '/' : 
             return (int)(i / j); 
        default : 
            cout << "operation not permitted" << endl; 
            break; 
    }
}
int calc(string s) { 
    stack<string> stk; 
    string operation; 
    string n1; 
    string n2; 

    for (int i = s.length()-1; i >= 0; i--) { 
        char c = s[i]; 
        if (c == '(' || c == ')' || c == ' ') 
            continue; 
        if (c == '+' || c == '-' || c == '/' || c == '*') { 
            operation = c;
            if (!stk.empty()) {  
                n1 = stk.top(); 
                stk.pop(); 
            }
            if (!stk.empty()) { 
                n2 = stk.top(); 
                stk.pop(); 
            }
            int localResult = doCalc(n1, n2, operation); 
            stk.push(to_string(localResult)); 
        } 
        else {
            string tmp(1,c);  
            stk.push(tmp); 
        } 
    } 
    return stoi(stk.top());     
}

int main() { 
    cout << calc("+ 2 4") << endl;
}
