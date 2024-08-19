#include <iostream>
#include <vector>

using namespace std;

// Bottom-UP DP, Top-Down DP

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n+1, 1),ans;
        dp[0] = 1;
        int i2=0, i3=0, i5=0;
        for (int i=1; i<= n; i++){
            int two = 2*dp[i2];
            int three = 3*dp[i3];
            int five = 5*dp[i5];
            int mn = min({two, three, five});
            dp[i] = mn;
            if (two == dp[i]) i2++;
            if (three == dp[i]) i3++;
            if (five == dp[i]) i5++;

        }
        return dp[n-1];
    }
};

/*

for the practies i solved this using python

class Solution:
    def solve(self, n:int, i2:int, i3:int, i5:int,i:int,dp:[]):
        
        if n == i:
            return dp[-1]

        two = 2*dp[i2]
        three = 3*dp[i3]
        five = 5*dp[i5]

        mn = min(two, three, five)

        dp.append(mn)

        if two == dp[i]: 
            i2+=1
        if three == dp[i]: 
            i3+=1
        if five == dp[i]: 
            i5+=1

        return self.solve(n,i2, i3, i5, i+1, dp)

    def nthUglyNumber(self, n: int) -> int:
        dp = [1]
        return self.solve(n,0,0,0,1,dp)
        

*/