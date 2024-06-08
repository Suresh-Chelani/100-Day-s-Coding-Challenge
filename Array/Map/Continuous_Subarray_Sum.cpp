#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// optimal
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> remainderMap;
        int cumulativeSum = 0;
        
        // Step 1: Initialize Remainder Map
        remainderMap[0] = -1;
        
        // Step 2: Iterate Through the List
        for (int i = 0; i < n; i++) {
            // Step 3: Calculate Cumulative Sum
            cumulativeSum += nums[i];
            
            // Step 4: Calculate Remainder
            int remainder = k == 0 ? cumulativeSum : cumulativeSum % k;
            
            // Step 5: Update Remainder Map
            if (remainderMap.count(remainder)) {
                // Check if segment length is at least two
                if (i - remainderMap[remainder] > 1) {
                    return true;
                }
            } else {
                remainderMap[remainder] = i;
            }
        }
        
        // Step 6: Return the Result
        return false;
    }
};

// brute force

// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         for (int i=0; i<n; i++){
//             long sum = nums[i];
//             for (int j=i+1; j<n; j++){
//                 sum += nums[j];
//                 if ((j - i + 1) >= 2 && sum % k == 0){
//                     return true;
//                 }
//             }  
//         }
        
//         return false;
//     }
// };