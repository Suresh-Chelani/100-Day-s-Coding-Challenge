#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int pre = 0;
        int suff = 0;
        for (int i=0; i<arr.size(); i++){
            suff += arr[i];
        }
        for (int i=0; i<arr.size(); i++){
            pre += arr[i];
            suff -= arr[i];
            if (pre == suff) 
                return true;
        }
        
        return false;
    }
};