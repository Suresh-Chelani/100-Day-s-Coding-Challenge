class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int window = count(nums.begin(), nums.end(), 1);
        if (window == 0) return 0; 

        int l = 0, r = window - 1;
        int mn_zero = 0, one = 0;

        for (int i = l; i <= r; i++) {
            if (!nums[i]) mn_zero++;
        }

        int min_zero = mn_zero;
        for (int i = 1; i < n; i++) {
            if (!nums[(l++) % n]) mn_zero--; 
            if (!nums[(r++ + 1) % n]) mn_zero++; 

            min_zero = min(min_zero, mn_zero); 
        }

        return min_zero;
    }
};
