#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 4)
            return 0;

        // Partial sort to get the smallest 4 elements in correct order
        partial_sort(nums.begin(), nums.begin() + 4, nums.end());
        // Use nth_element to ensure the 4th largest element is in the correct position
        nth_element(nums.begin() + 4, nums.begin() + (n - 4), nums.end());
        // Sort the largest 4 elements
        sort(nums.end() - 4, nums.end());

        int ans = INT_MAX;
        // Calculate the minimum difference for all possible combinations of changing 3 elements
        for (int i = 0; i <= 3; ++i)
        {
            ans = min(ans, nums[n - 1 - i] - nums[3 - i]);
        }

        return ans;
    }
};

/*

// 1,5,0,10,14, 9, 3,2 6


// 0 1 2 3 5 6 9 10 14

// Here only for condition which is important for solving this question
// because only we have three moves due to that 4 possible way to change,
// number with optimal to find the min diff.

// nums[n - 1] - nums[3]

// nums[n - 2] - nums[2]

// nums[n - 3] - nums[1]

// nums[n - 4] - nums[0]

*/

/*



class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;

        sort(nums.begin(), nums.end());

        int ans = INT_MAX;
        for (int i = 0; i <= 3; ++i) {
            ans = min(ans, nums[n - 1 - i] - nums[3 - i]);
        }

        return ans;

    }
};




*/