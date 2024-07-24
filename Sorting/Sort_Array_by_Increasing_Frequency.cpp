#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

// solution 1:

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for (int val: nums) mp[val]++;
        auto lambda = [&](const int &a, const int &b){
            if (mp[a] == mp[b]) return a > b;
            return mp[a] < mp[b];
        };
        sort(nums.begin(), nums.end(), lambda);
        return nums;
    }
};

// solution 2:

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        vector<int>ans;
        vector<pair<int,int>>vec(n);
        for (int val: nums) mp[val]++;
        for (auto &item: mp) vec.push_back({item.first, item.second});

        auto lambda = [](const pair<int,int>& a, pair<int,int>& b){
            if (a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        };

        sort(vec.begin(),vec.end(), lambda);

        for (auto &item: vec)
            for (int i=0; i<item.second; i++) 
                ans.push_back(item.first);
        
        return ans;
    }
};


// solution 3:

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        vector<int>ans;
        vector<pair<int,int>>vec(n);
        for (int val: nums) mp[val]++;
        for (auto &item: mp) vec.push_back({item.second, item.first});
        sort(vec.begin(),vec.end());
        int m = vec.size();
        for (int i=0; i<m; i++){
            if (i < m - 1 && vec[i].first != vec[i+1].first){
                for (int j=0; j < vec[i].first; j++) ans.push_back(vec[i].second);                
            }
            else if (i < m - 1 && vec[i].first == vec[i+1].first){
                int indx = vec[i].first;
                int k = i;
                while (indx == vec[k].first) k++;

                for (int j = k - 1; j >= i; j--){
                    for (int p=0; p < vec[j].first; p++) ans.push_back(vec[j].second);                    
                }
                i = k - 1;
            }
            else {
                for (int j=0; j < vec[i].first; j++) ans.push_back(vec[i].second);
            }
        }

        return ans;
    }
};
