#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void solve(vector<int>& curr, vector<int>& nums, unordered_set<int>& s) {
        if (n == curr.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (s.find(nums[i]) == s.end()) { 
                curr.push_back(nums[i]);
                s.insert(nums[i]);
                solve(curr, nums, s);
                curr.pop_back();
                s.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        vector<int> curr;
        unordered_set<int> s; // Use a local set for each permutation generation
        n = nums.size();
        solve(curr, nums, s);  
        return ans;
    }
};


// class Solution {
// public:
//     vector<vector<int>> ans;
//     int n;

//     void solve(vector<int>& curr, vector<int>& nums, vector<bool>& check) {
//         if (n == curr.size()) {
//             ans.push_back(curr);
//             return;
//         }

//         for (int i = 0; i < n; i++) {
//             if (!check[i]){
//                 check[i] = true;
//                 curr.push_back(nums[i]);
//                 solve(curr, nums, check);
//                 check[i] = false;
//                 curr.pop_back();
//             }
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {
//         ans.clear();
//         vector<int> curr;
//         n = nums.size();
//         vector<bool> check(n, false);
//         solve(curr, nums, check);  
//         return ans;
//     }
// };

int main() {
    Solution obj;
    int n; 

    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> ans = obj.permute(arr);

    for (const auto& permutation : ans) {
        for (int val : permutation) {
            cout << val << " ";
        }
        cout << endl;
    }
}
