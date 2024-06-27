#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mp;
        int n = edges.size();
        for (int i=0; i<n; i++){
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }

        for (auto &item: mp){
            if (item.second == n){
                return item.first;
            }
        }

        return 0;
    }
};