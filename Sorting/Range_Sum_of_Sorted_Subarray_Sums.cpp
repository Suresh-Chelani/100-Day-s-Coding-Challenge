class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>arr;
        int mod = 1e9+7;
        for (int i=0; i<n; i++){
            int curr = 0;
            for (int j=i; j<n; j++){
                curr += nums[j];
                arr.push_back(curr);
            }
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i=left-1; i<right; i++){
            ans = (ans + arr[i])%mod;
        }
        return ans;
    }
};

 
