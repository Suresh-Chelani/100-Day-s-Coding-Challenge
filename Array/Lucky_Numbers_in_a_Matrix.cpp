#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            int mn = INT_MAX;
            int col = -1;
            bool ok = true;
            for (int j = 0; j < m; j++)
            {

                if (mn > matrix[i][j])
                {
                    mn = matrix[i][j];
                    col = j;
                }
            }

            for (int k = 0; k < n; k++)
            {
                if (mn < matrix[k][col])
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans.push_back(mn);
        }

        return ans;
    }
};