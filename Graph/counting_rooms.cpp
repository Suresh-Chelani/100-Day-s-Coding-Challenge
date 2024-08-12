#include <iostream>
#include <vector>

using namespace std;


int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};
void DFS(vector<vector<char>>& grid, int i, int j){
    grid[i][j] = '#';
    for (int k=0; k<4; k++){
        int new_i = dx[k] + i;
        int new_j = dy[k] + j;

        if (new_i < grid.size() && new_i >= 0 && new_j >= 0 && new_j < grid[0].size() && grid[new_i][new_j] == '.'){
            DFS(grid, new_i, new_j);
        }
    }
}

int main(){

    int n, m;

    cin >> n >> m;

    int ans = 0;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> grid[i][j];
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (grid[i][j] == '.'){
                DFS(grid, i, j);
                ans += 1;
            }
        }
    }
    
    cout << ans << endl; 
    


    return 0;
}

// same as no' of island
