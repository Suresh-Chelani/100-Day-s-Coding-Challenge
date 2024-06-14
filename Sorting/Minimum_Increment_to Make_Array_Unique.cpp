#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int moves = 0;

        for (int i=1; i<nums.size(); i++){
            if (nums[i-1] >= nums[i]){
                moves += nums[i-1] - nums[i] + 1;
                nums[i] += nums[i-1] - nums[i] + 1;
            }
        }

        return moves;
    }
};



/*

Topics:
Array, Greedy, Sorting, Counting

*/

/*
Using: set with sorting


class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int moves = 0;
        set<int>st;

        for (int i=0; i<nums.size(); i++){
            if (st.find(nums[i]) != st.end()){
                auto val = st.rbegin();
                if (*val < nums[i]){
                    st.insert(nums[i]);
                }
                else{
                    moves += *val - nums[i] + 1;
                    st.insert(nums[i] + (*val - nums[i] + 1));
                }
            }
            else{
                st.insert(nums[i]);
            }
        }

        return moves;
    }
};


*/