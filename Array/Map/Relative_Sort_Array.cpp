#include <iostream>
#include<vector>
#include<map>

using namespace std;


class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans,im;
        map<int, int>mp;

        for (int val: arr1){
            mp[val]++;
        }

        for (int i=0; i<arr2.size(); i++){
            int val = arr2[i];

            while (mp[val]--){
                ans.push_back(val);
            }
        }

        for (auto &item: mp){
            if (item.second > 0){
                while (item.second--){
                    ans.push_back(item.first);
                }
            }
        }
        return ans;

    }
};
