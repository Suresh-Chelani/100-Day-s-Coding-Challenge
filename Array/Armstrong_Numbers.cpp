#include <iostream>

using namespace std;

class Solution {
  public:
    string armstrongNumber(int n){
        int save = n;
        int sum = 0;
        sum = pow(n%10, 3) + pow((n/10)%10, 3) + pow((n/100)%10, 3);
        if (save == sum) return "Yes";
        return "No";
    }
};

/*
class Solution {
  public:
    string armstrongNumber(int n){
        int save = n;
        int sum = 0;
        while (n){
            int digit = n % 10;
            sum += pow(digit,3);
            n/=10;
        }
        
        if (save == sum) return "Yes";
        return "No";
    }
};

*/