#include <iostream>
using namespace std;


class Solution {
public:
    int solve(int count, int copy, int& n){
        if (count == n) return 0;
        if (count > n || copy > n) return 1e9;
        int paste = 1 + solve(count+copy, copy, n);
        int copypaste = 2 + solve(count+count, count, n);
        return min(paste, copypaste);
    }
    int minSteps(int n) {
        if (n==1) return 0;
        return 1+solve(1,1,n);
    }
};