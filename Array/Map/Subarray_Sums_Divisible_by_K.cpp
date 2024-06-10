#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int sum = 0;
        int res = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int mod = sum % k;
            if (mod < 0) {
                mod += k; // Ensure the modulus is positive
            }
            if (map.find(mod) != map.end()) {
                res += map[mod];
            }
            map[mod]++;
        }
        
        return res;
    }
};

