#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mx = INT_MIN;
        int mn = INT_MAX;
        int n = arrays.size();
        pair<int,int> p = {0,0};
        for (int i=0; i<n; i++){
            int curr_mn = arrays[i][0];
            int curr_mx = arrays[i][arrays[i].size()-1];

            if (mx < curr_mx){
                p.first = i;
                mx = curr_mx;
            }

            if (mn > curr_mn){
                p.second = i;
                mn = curr_mn;
            }
        }
        
        if (p.first != p.second) return mx - mn;

        int mx2 = INT_MIN;
        int mn2 = INT_MAX;

        for (int i=0; i<n; i++){
            int curr_mn = arrays[i][0];
            int curr_mx = arrays[i][arrays[i].size()-1];

            if (mx2 < curr_mx && p.first != i){
                mx2 = curr_mx;
            }

            if (mn2 > curr_mn && p.second != i){
                mn2 = curr_mn;
            }
        }

        return max(mx - mn2, mx2 - mn);
    }
};


// [[2,3],[1,4,5],[2,3]]

// -> diff -> indx return []
// -> same -> indx -> min, max