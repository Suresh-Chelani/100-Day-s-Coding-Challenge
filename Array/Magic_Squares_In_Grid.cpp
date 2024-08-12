class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int i, int j){
        set<int> st;
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                st.insert(grid[i + x][j + y]);
            }
        }

        if (st.size() != 9 || *st.begin() != 1 || *st.rbegin() != 9) {
            return false;
        }

        int sum1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
        int sum2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
        int sum3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
        int sum4 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
        int sum5 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
        int sum6 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
        int sum7 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
        int sum8 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];

        if (sum1 == sum2 && sum2 == sum3 &&
            sum3 == sum4 && sum4 == sum5 &&
            sum5 == sum6 && sum6 == sum7 &&
            sum7 == sum8) {
            return true;
        }

        return false;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (isMagic(grid,i,j)) count++;
            }
        }

        return count;
    }
};
