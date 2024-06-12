#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one = 0, two = 0, zero = 0;
        int i = 0;
        for (int val: nums){
            one = val == 1 ? one + 1 : one;
            two = val == 2 ? two + 1 : two;
            zero = val == 0 ? zero + 1 : zero;
        }
        while (zero--) nums[i++] = 0;
        
        while (one--) nums[i++] = 1;

        while (two--) nums[i++] = 2;
    }
};