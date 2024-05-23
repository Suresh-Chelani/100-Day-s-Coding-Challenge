#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int n;
    void solve(int i, vector<int>& nums, int& k, vector<int>& curr, int& count){
        if (i == n){
            for (int l=0; l<curr.size(); l++){
                for (int j=0; j<curr.size(); j++){
                    if (abs(curr[l] - curr[j]) == k){
                        return ;
                    }
                }
            }
            count += 1;
            return;
        }
        curr.push_back(nums[i]);
        solve(i+1, nums, k, curr, count);
        curr.pop_back();
        solve(i+1, nums, k, curr, count);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        n = nums.size();
        int count = 0;
        vector<int>curr;
        solve(0, nums, k, curr, count);
        return count-1;
    }
};

int main(){
    Solution obj;
    int n, k; 
    cin >> n >> k;
    vector<int>nums(n);

    for (int i=0; i<n; i++) cin >> nums[i];

    int ans = obj.beautifulSubsets(nums, k);

    cout << ans << endl;
}