#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;

        for (int &val: bills){
            if (val == 5){
                five+=1;
            }
            else if (val == 10 && five){
                five-=1;
                ten +=1;
            }
            else if (val == 20 && five && ten){
                five-=1;
                ten -=1;
                twenty +=1;
            }
            else if (val == 20 && five >= 3){
                five -=3;
                twenty += 1;
            }
            else{
                return false;
            }
        }

        return true;
    }
};
