#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isodd(int n) {return n%2!=0;}
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for (int i=2; i<n; i++){
            if (isodd(arr[i]) && isodd(arr[i-1]) && isodd(arr[i-2])) 
                return true;
        }
        return false;
    }
};