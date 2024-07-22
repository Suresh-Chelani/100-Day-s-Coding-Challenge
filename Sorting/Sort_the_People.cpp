#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;



class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        vector<string>ans(n);
        vector<int>indices(n);
        iota(indices.begin(), indices.end(), 0);

        auto lambda = [&](int &i, int &j){
            return heights[i] > heights[j];
        };

        sort(indices.begin(), indices.end(), lambda);
        
        for (int i=0; i<n; i++){
            ans[i] = names[indices[i]]; 
        }

        return ans;
    }
};

/*
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        vector<string>ans(n);
        vector<pair<int,int>>vec(n);
        for (int i=0; i<n; i++){
            vec[i].first = heights[i];
            vec[i].second = i;
        }

        sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        for (int i=0; i<n; i++){
            ans[i] = names[vec[i].second]; 
        }

        return ans;
    }
};

*/
