#include <iostream>
#include <vector>

using namespace std;

#include <vector>
using namespace std;

class Solution {
public:
    int countLessThanEqualToK(vector<int>& nums, int k) {
        int i = 0; 
        int count = 0; 
        int oddCount = 0; 
        
        for (int j = 0; j < nums.size(); ++j) { 
            if (nums[j] % 2 == 1) 
                oddCount++; 
            while (oddCount > k) {
                if (nums[i] % 2 == 1)
                    oddCount--;
                i++;
            } 
            
            count += j - i + 1;
        }
        return count; 
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countLessThanEqualToK(nums, k) - countLessThanEqualToK(nums, k - 1);
    }

};