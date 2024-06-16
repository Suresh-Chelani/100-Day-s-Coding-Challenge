#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<int> mp(24, 0);
        long long count = 0;
        
        for (int hour : hours) {
            int remainder = hour % 24;
            int complement = (24 - remainder) % 24;
            count += mp[complement];
            mp[remainder]++;
        }
        
        return count;
    }
};
