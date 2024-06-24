#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int flips = 0;
        int n = nums.size();
        vector<int> flipCount(n, 0);

        int tempCount = 0;

        if (nums[0] == 0)
        {
            flipCount[k - 1] = 1;
            tempCount = 1;
            flips++;
        }

        for (int i = 1; i <= n - k; i++)
        {
            tempCount -= flipCount[i - 1];
            tempCount += flipCount[i + k - 1];

            int negVal = nums[i] == 0 ? 1 : 0;
            int val = tempCount % 2 == 0 ? nums[i] : negVal;

            if (val == 0)
            {
                flipCount[i + k - 1] = 1;
                flips++;
                tempCount++;
            }
        }

        for (int i = n - k + 1; i < n; i++)
        {
            tempCount -= flipCount[i - 1];
            int negVal = nums[i] == 0 ? 1 : 0;
            int val = tempCount % 2 == 0 ? nums[i] : negVal;

            if (val == 0)
            {
                return -1;
            }
        }

        return flips;
    }
};