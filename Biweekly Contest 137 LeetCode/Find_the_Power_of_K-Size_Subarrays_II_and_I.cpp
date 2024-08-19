#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1, 0);
        long curr = 0;

        for (int i = 0; i < k; i++) {
            curr += nums[i];
        }


        for (int i = 0; i <= n - k; i++) {
            int val = nums[i];
             long sum = (long)(k) * (2 * (long)(val) + (k - 1)) / 2;
            
           
            if (nums[i + k - 1] == val + k - 1 && sum == curr) {
                ans[i] = nums[i + k - 1];
            } else {
                ans[i] = -1;
            }

            
            if (i + k < n) {
                curr += nums[i + k]; 
                curr -= nums[i];     
            }
        }

        return ans;
    }
};