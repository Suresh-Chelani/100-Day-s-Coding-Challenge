class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int>mp(1001, 0);
        int n = target.size();
        for (int i=0; i<n; i++){
            mp[target[i]]++;
            mp[arr[i]]--;
        }
        return !any_of(mp.begin(), mp.end(), [](int item) {
            return item != 0;
        });
    }
};
