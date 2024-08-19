#include <iostream>

using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        int total = 0;

        for (int i = 0; i < n; i++) {
            int one = 0;
            int zero = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1') {
                    one += 1;
                } else {
                    zero += 1;
                }

                if (one <= k || zero <= k) {
                    total += 1;
                } else {
                    break;
                }
            }
        }

        return total;
    }
};
