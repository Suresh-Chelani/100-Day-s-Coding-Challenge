#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;
        for (int val: nums) x ^= val; // xor for all the element 
        int mark = (x & (-x)); // create the mark for searching, which right most bit is set..
        int a = 0, b = 0;
        for (int val: nums){
            if (mark&val) a ^= val; // grouping the elements according to the mark and doing xor for the individual  
            else b ^= val;
        }
        return {a,b};
    }
};

int main(){
    Solution obj;
    int n;
    cin >> n;
    vector<int>nums(n);
    for (int i=0; i<n; i++) cin >> nums[i];
    vector<int>arr = obj.singleNumber(nums);
    cout << arr[0] << " " << arr[1];
    return 0;
}