#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void solve(int i, vector<int>& nums) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int j = i; j < n; j++) {
            swap(nums[i], nums[j]);
            solve(i+1, nums);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        solve(0, nums);  
        return ans;
    }
};

int main() {
    Solution obj;
    int n; 

    cin >> n;
    vector<int> arr;
    int val = 0;
    for (int i = 0; i < n; i++) {
        cin >> val;
        arr.push_back(val);
    }

    vector<vector<int>> ans = obj.permute(arr);

    for (const auto& permutation : ans) {
        for (int val : permutation) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// time: O(n! * n), ~ for genrating the all permutaion and with each permutation take n time for storing
//                       the permutation in ans 2D vector.
// space: O(n) (recursion depth space) + O(n!) (for storing the permutation in 2D ans vector)