#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
        int n = diff.size();
        int mx = *max_element(worker.begin(), worker.end());
        vector<int>arr(mx+1, 0);

        for (int i=0; i<n; i++){
            if (diff[i] <= mx){
                arr[diff[i]] = max(profit[i], arr[diff[i]]);
            }
        }
        for (int i=1; i<=mx; i++){
            arr[i] = max(arr[i], arr[i-1]);
        }
        int ans = 0;
        for (int i=0; i<worker.size(); i++){
            ans += arr[worker[i]];
        }
        return ans;
    }
};
