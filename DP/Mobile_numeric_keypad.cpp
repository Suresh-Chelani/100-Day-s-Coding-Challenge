#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
         if (n <= 0) return 0;

    // Initialize the dp array
    vector<vector<long long>> dp(n+1, vector<long long>(10, 0));

    // Initialize the vec with adjacency lists
    vector<vector<int>> vec(10);
    vec[0] = {0, 8};
    vec[1] = {1, 2, 4};
    vec[2] = {1, 2, 3, 5};
    vec[3] = {2, 3, 6};
    vec[4] = {1, 4, 5, 7};
    vec[5] = {2, 4, 5, 6, 8};
    vec[6] = {3, 5, 6, 9};
    vec[7] = {4, 7, 8};
    vec[8] = {0, 5, 7, 8, 9};
    vec[9] = {6, 8, 9};

    // Base case: length 1
    for (int i = 0; i < 10; ++i) {
        dp[1][i] = 1;
    }

    // Fill the dp array for lengths 2 to n
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int prev : vec[j]) {
                dp[i][j] += dp[i - 1][prev];
            }
        }
    }

    // Sum up all the ways to get sequences of length n
    long long sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += dp[n][i];
    }

    return sum;
    }
};

