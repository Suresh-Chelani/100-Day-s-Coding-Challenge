// Using Top Down Approach:

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int prod = 9;
        int curr = 9;
        int ans = 10; // start from n = 1

        for (int i=2; i <= n; i++){
            curr *= prod;
            ans += curr;
            prod--;
        }

        return ans;
    }
};


// Brute Force

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int unique = 0;
        for (int i=0; i<pow(10,n); i++){
            unordered_map<int,int>mp;
            int val = i;
            bool ok = true;
            while (val){
                int digit = val % 10;
                mp[digit]+=1;
                val/=10;
                if (mp[digit] > 1) {
                    ok = false;
                    break;
                }
            }

            if (ok) unique+=1;
        }

        return unique;
    }
};
