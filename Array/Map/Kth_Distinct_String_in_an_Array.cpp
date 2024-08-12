class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;
        for (auto &st: arr) mp[st]++;

        for (string &st: arr){
            if (mp[st] == 1 && k == 1) return st;
            if (mp[st] == 1 && k > 1) k--;
        }
        return "";
    }
};
