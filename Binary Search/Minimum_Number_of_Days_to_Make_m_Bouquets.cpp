#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int makeBouquets(vector<int>& bloomDay, int& mid, int& k){
        int count = 0;
        int coutinue_count = 0;

        for (int i=0; i<bloomDay.size(); i++){
            if (bloomDay[i] <= mid){
                coutinue_count += 1;
            }
            else{
                coutinue_count = 0;
            }

            if (coutinue_count == k){
                count+=1;
                coutinue_count = 0;
            }
        }

        return count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int l = 0;
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (l <= r){
            int mid = l + (r - l)/2;

            if (makeBouquets(bloomDay, mid, k) >= m){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};