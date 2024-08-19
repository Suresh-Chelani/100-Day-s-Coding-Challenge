class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<int>arr(mx+1, 0);
        for (int i=0; i < n; i++){
            for (int j=i+1; j < n; j++){
                arr[abs(nums[i]-nums[j])]++;
            }
        }
        for (int i=0; i<arr.size(); i++){
            k-=arr[i];
            if (k <= 0) return i;

        }
        return -1;
    }
};


