#include <stdlib.h>
#include <stdio.h>
#include <iostream> 
#include <vector> 

using namespace std; 

int get_combos(string s) { 
    if (s.length() == 0) 
        return 0; 
    vector<int> dp; 
    dp.resize(s.length()); 
    dp[0] = 1; 
    for (int i = 1; i < s.length() ; i++) { 
        int cur_num = (s[i-1] - '0') * 10 + (s[i] - '0'); 
        if (dp[i-1] != 0) 
            dp[i] += dp[i-1]; 
        if (cur_num <= 25) 
            dp[i] += i == 1 ? 1 : dp[i-2]; 
    }
    return dp[s.length()-1];  
}

int main() { 
   string test = "13"; 
    cout << get_combos(test) << endl; 
}
