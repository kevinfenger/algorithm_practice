#include <stdlib.h> 
#include <iostream>
#include <vector>  

using namespace std; 
void pretty_print_matrix(vector<vector<int> >, int, int); 


void 
rotate_matrix(int height, int width) 
{
    vector<vector<int> > matrix; 
    matrix.resize(height); 
    for (int i = 0; i < height; i++) 
        matrix[i].resize(width); 
    for (int i = 0; i < height; i++) { 
        for (int j = 0; j < width; j++) { 
            matrix[i][j] = rand() % 10; 
        } 
    }
    pretty_print_matrix(matrix, height, width); 

    for (int layer = 0; layer < (height / 2); layer++) {  
       int first = layer; 
       int last = height - 1 - layer; 
       for (int i = first; i < last; i++) { 
           int offset = i - first; 
           int top = matrix[first][i]; 
           matrix[first][i] = matrix[last-offset][first]; 
           matrix[last-offset][first] = matrix[last][last-offset];
           matrix[last][last-offset] = matrix[i][last];
           matrix[i][last] = top; 
       }
    }
    pretty_print_matrix(matrix, height, width); 
} 

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

int main() { 
    srand(time(0)); 
    cout << (3 / 2);
    rotate_matrix(3,3); 
}
