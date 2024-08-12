class Solution {
public:
    int row,col;
    void BFS(vector<vector<int>>& mx, int i, int j){
        int dx[4] = {-1,0,0,1};
        int dy[4] = {0,1,-1,0};
        queue<pair<int,int>>q;
        q.push({i,j});
        mx[i][j] = -1;

        while (!q.empty()){
            auto node = q.front();
            q.pop();
            for (int k=0; k<4; k++){
                int new_i = dx[k] + node.first;
                int new_j = dy[k] + node.second;
                if (new_i < row && new_i >= 0 && new_j >= 0 && new_j < col && mx[new_i][new_j] == 0){
                    q.push({new_i, new_j});
                    mx[new_i][new_j] = -1;
                }
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int _regions = 0;
        row = n*3;
        col = m*3;
        vector<vector<int>>mx(row, vector<int>(col, 0));

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == '/'){
                    mx[i*3][j*3+2] = 1;
                    mx[i*3+1][j*3+1] = 1;
                    mx[i*3+2][j*3] = 1;
                }
                else if (grid[i][j] == '\\'){
                    mx[i*3][j*3] = 1;
                    mx[i*3+1][j*3+1] = 1;
                    mx[i*3+2][j*3+2] = 1;
                } 
            }
        }
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                if (mx[i][j] == 0){
                    BFS(mx,i,j);
                    _regions++;
                }
            }
        }

        return _regions;
    }
};

// grid[i][j] == / => 
//     [
//     [0,0,1],
//     [0,1,0],
//     [1,0,0]
//     ]

// grid[i][j] == \\ => 
//     [
//     [1,0,0],
//     [0,1,0],
//     [0,0,1]
//     ]
