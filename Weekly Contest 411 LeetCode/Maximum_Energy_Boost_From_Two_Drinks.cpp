#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> energyDrinkA, energyDrinkB;
    long long dp[100005][2]; 
    long long maxBoost(int i, int last, int n) {
        if (i >= n) return 0; 

        if (dp[i][last] != -1) return dp[i][last];

        if (last == 0) {
            dp[i][last] = max(maxBoost(i + 1, 0, n) + energyDrinkA[i],maxBoost(i + 2, 1, n) + energyDrinkA[i]);
        } else { 
            dp[i][last] = max(maxBoost(i + 1, 1, n) + energyDrinkB[i],maxBoost(i + 2, 0, n) + energyDrinkB[i]);
        }

        return dp[i][last];
    }

    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        this->energyDrinkA = energyDrinkA;
        this->energyDrinkB = energyDrinkB;

        memset(dp, -1, sizeof(dp));

        return max(maxBoost(0, 0, n), maxBoost(0, 1, n));
    }
};