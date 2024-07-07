#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        vector<vector<int>> preX(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> preY(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                preX[i][j] = preX[i - 1][j] + preX[i][j - 1] - preX[i - 1][j - 1] + (grid[i - 1][j - 1] == 'X');
                preY[i][j] = preY[i - 1][j] + preY[i][j - 1] - preY[i - 1][j - 1] + (grid[i - 1][j - 1] == 'Y');
            }
        }

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                int c_x = preX[i][j];
                int c_y = preY[i][j];
                if (c_x == c_y && c_x > 0)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};