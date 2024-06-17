#include <iostream>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        
        int l = 0, r = sqrt(c);

        while (l <= r){
            long curr = pow(l,2) + pow(r,2);

            if (curr < c){
                l += 1;
            }
            else if (curr == c) {
                return true;
            }
            else{
                r -= 1;
            }
        }
        
        return false;
    }
};