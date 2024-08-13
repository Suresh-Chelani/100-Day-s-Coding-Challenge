// Approach1: Using Backtracking: 

class Solution {
public:
    void solve(int i, vector<int>& arr, vector<int> empty, int target, vector<vector<int>>& ans){
        if (i == arr.size()) {
            if (target == 0){
                ans.push_back(empty);
            }
            return ;
        }
        if (arr[i] <= target) {
            empty.push_back(arr[i]);
            solve(i+1, arr, empty, target - arr[i],ans);
            empty.pop_back();
        }
        while (i+1 < arr.size() && arr[i] == arr[i+1]) i+=1;
        solve(i+1, arr, empty, target, ans);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        solve(0,candidates, {}, target,ans);
        return ans;
    }
};

// Approach2: Using DP

class Solution {
public:
    vector<vector<vector<vector<int>>>> dp;
    vector<vector<int>> solve(int i, vector<int>& arr, int target) {
        if (target == 0) return {{}};
        if (i >= arr.size() || target < 0) return {};
        if (!dp[i][target].empty()) return dp[i][target];
        
        vector<vector<int>> result;
        
        // Include current element if it's not exceeding the target
        for (int j = i; j < arr.size(); j++) {
            if (j > i && arr[j] == arr[j - 1]) continue; // Skip duplicates
            if (arr[j] > target) break; // No need to proceed further
            
            auto include = solve(j + 1, arr, target - arr[j]);
            for (auto &comb : include) {
                comb.push_back(arr[j]);
                result.push_back(comb);
            }
        }
        
        // Store the result in dp table
        dp[i][target] = result;
        return result;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort the candidates to help manage duplicates
        sort(candidates.begin(), candidates.end());
        dp.resize(candidates.size(), vector<vector<vector<int>>>(target + 1));
        return solve(0, candidates, target);
    }
};
