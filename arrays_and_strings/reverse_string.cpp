#include <stdio.h> 
#include <stdlib.h>
#include <iostream> 
#include <string.h> 

using namespace std; 

void 
reverse(char* str) 
{
    char* end = str; 
    while (*end) {
        ++end; 
    } 
    end--;  
    
    while (str < end) { 
        char tmp = *str; 
        *str++ = *end; 
        *end-- = tmp; 
    }    
}

void 
other_reverse(char str[]) 
{ 
    int l,r; 
    for (l=0, r=strlen(str)-1; l < r; l++, r--) 
    { 
//       char tmp = str[l]; 
//       str[l] = str[r];
//       str[r] = tmp; 
        str[l] ^= str[r]; 
        str[r] ^= str[l]; 
        str[l] ^= str[r]; 
    }
    str[strlen(str)] = '\0'; 
} 

int 
atoi_copy(char* str) 
{
    if (str == NULL)  
         return 0; 
        
    int res=0, sign=1, i=0, 
        length = strlen(str)-1; 
    if (str[0] == '-') { 
        sign = -1; 
        i++; 
    } 
    for (; i <= length; i++) { 
        res = res*10 + str[i] - '0'; 
    }
    return res; 
}

int main() {
    char blah[] = "kkkikkkn";
    other_reverse(blah);
    cout << blah;  
    char blah2[] = "-12345"; 
    cout << atoi_copy(blah2); 
}
