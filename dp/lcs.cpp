#include <stdio.h>
#include <stdlib.h> 
#include <vector>
#include <iostream> 

using namespace std; 

void 
pretty_print_matrix(vector<vector<int> > matrix, int height, int width) 
{ 
    cout << endl << "Matrix : " << endl; 
    for (int i = 0; i < height; i++) { 
        for (int j = 0; j < width; j++) {
            cout << matrix[i][j] << " "; 
        } 
        cout << endl; 
    }
    cout << endl;  
} 

string 
find_lcs(string sone, string stwo) { 
    vector<vector<int> > table;
    int height = sone.length() + 1; 
    int width  = stwo.length() + 1; 
    table.resize(height); 
 
    for (int i = 0; i < height ; i++) { 
        table[i].resize(width);     
    }
    pretty_print_matrix(table, height, width);  
    return ""; 
//    for (int i = 0; i < height; i++) { 
//        table[0][i] = 0; 
//    } 
//    for (int j = 0; j < width; j++) { 
//        table[j][0] = 0; 
//    } 
}

int main() { 
    find_lcs("gat", "agcat"); 
}
