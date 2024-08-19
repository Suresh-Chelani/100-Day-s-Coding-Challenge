#include <iostream>
#include <vector>

using namespace std;


//Time: O(n), Space: O(1)
class Solution {
public:
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        int n = nums.size();
        vector<long long int> ans(n, 1);

        long long int pre = 1;
        long long int suff = 1; 

        for (int i = 0; i < n; i++) {
            ans[i] = pre; 
            pre *= nums[i]; 
        }

        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suff; 
            suff *= nums[i];
        }

        return ans;
    }
};


/*
Time: O(n), Space: O(n)
class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        int n = nums.size();
        vector<long long int>suff(n+1, 1);
        vector<long long int> ans;
        suff[n-1] = nums[n-1];
        for (int i=n-2; i>=0; i--) suff[i] = nums[i]*suff[i+1];
        long long int pre = 1;
        for (int i=0; i<n; i++){
            ans.push_back(pre*suff[i+1]);
            pre*= nums[i];
        }
        return ans;
    }
};

*/