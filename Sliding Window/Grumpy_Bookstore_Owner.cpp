#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int maxUnsat = 0;
        int currUnsat = 0;
        for (int i=0; i<minutes; i++) 
            currUnsat += customers[i]*grumpy[i];
        maxUnsat = currUnsat;
        int i=0;       
        for (int j=minutes; j < n; j++){
            currUnsat += customers[j]*grumpy[j];
            currUnsat -= customers[i]*grumpy[i];
            maxUnsat = max(maxUnsat, currUnsat);
            i++;
        }
        int total_satisfied = maxUnsat;

        for (int i=0; i<n; i++){
            total_satisfied += customers[i]*(1 - grumpy[i]);
        }
        return total_satisfied;
    }
};

