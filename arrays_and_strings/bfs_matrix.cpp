#nclude <stdlib.h>
#include <stdio.h>
#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std; 
#define ROWS 5
#define COLS 5

bool 
safe(vector<vector<int> > matrix, vector<vector<bool> > visited, int row, int col) { 
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && matrix[row][col] && !visited[row][col]); 
}
void 
dfs(vector<vector<int> > matrix, vector<vector<bool> > & visited, int row, int col) { 
    visited[row][col] = true; 
    if (safe(matrix, visited, row - 1, col)) 
       dfs(matrix, visited, row - 1, col); 
    if (safe(matrix, visited, row - 1, col + 1)) 
       dfs(matrix, visited, row - 1, col + 1); 
    if (safe(matrix, visited, row, col + 1))  
       dfs(matrix, visited, row, col + 1); 
    if (safe(matrix, visited, row + 1, col + 1)) 
       dfs(matrix, visited, row + 1, col + 1); 
    if (safe(matrix, visited, row + 1, col)) 
       dfs(matrix, visited, row + 1, col); 
    if (safe(matrix, visited, row + 1, col - 1)) 
       dfs(matrix, visited, row + 1, col - 1); 
    if (safe(matrix, visited, row + 0, col - 1))
       dfs(matrix, visited, row + 0, col - 1); 
    if (safe(matrix, visited, row - 1, col - 1)) 
       dfs(matrix, visited, row - 1, col -1); 
}
int 
bfs(vector<vector<int> > matrix, int row, int col) { 
   vector<vector<bool> > visited; 
   for (int i = 0; i < ROWS; i++) 
       for (int j = 0; j < COLS; j++)  
           visited[i][j] = false;
   
   queue<pair<int,int> > q; 
   visited[row][col] = true; 
   q.push(make_pair(row,col)); 
   
   while (!q.empty()) { 
      pair<int, int> p = q.front(); 
      q.pop(); 
      
      if (!visited[row - 1][col]) { 
          visited[row-1][col] = true; 
          q.push(make_pair(row-1, col)); 
      }
      // ...
   } 
}
int
getIslandCount(vector<vector<int> > matrix, int height, int width) { 
    int count = 0; 
    vector<vector<bool> > visited; 
    visited.resize(height); 
    for (int i = 0; i < height; i++) 
        visited[i].resize(width); 
    
    for (int i = 0; i < height; i++) 
        for (int j = 0; j < width; j++)  
            visited[i][j] = false;

    for (int i = 0 ; i < height; i++) { 
        for (int j = 0; j < width; j++) { 
            if (matrix[i][j] == 1 && !visited[i][j]) { 
                count++; 
                dfs(matrix, visited, i, j); 
            } 
        }
    }
    return count; 
}

int main() {
    int height = 5; 
    vector<vector<int> > matrix;  
    matrix.resize(5); 
    for (int i = 0; i < height; i++) 
        matrix[i].resize(5); 

}
