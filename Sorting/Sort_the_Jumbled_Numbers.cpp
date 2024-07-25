#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int val : nums) {
            int num = val;
            if (val == 0) {
                mp[val] = mapping[val];
                continue;
            }
            int new_val = 0;
            int multi = 1;
            while (val) {
                int last = val % 10;
                new_val = mapping[last] * multi + new_val;
                multi *= 10;
                val /= 10;
            }
            mp[num] = new_val;
        }

        sort(nums.begin(), nums.end(), [&](const int& a, const int& b) {
            return mp[a] < mp[b];
        });
        
        return nums;
    }
};
