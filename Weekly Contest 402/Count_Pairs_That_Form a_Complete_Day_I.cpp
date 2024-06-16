#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int count = 0;
        int n = hours.size();
        for (int i=0; i<n; i++){
            for (int j = i+1; j < n; j++){
                int val = hours[i]+hours[j];
                if (val % 24 == 0){
                    count++;
                }
            }
        }
        
        return count;
    }
};