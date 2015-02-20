#include <stdlib.h> 
#include <stdio.h> 
#include <iostream> 

using namespace std; 

void print_all_ascii(int x) { 
    if (x < 0) 
        return; 
    cout << (char)(x); 
    print_all_ascii(x-1); 
}

int main() { 
    print_all_ascii(128); 
}
