#include<iostream>

using namespace std;

class Solution {
public:
    string addOne(string s){
        int n = s.size();
        int carry = 1; 

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1' && carry == 1) {
                s[i] = '0';
                carry = 1; 
            } else if (s[i] == '0' && carry == 1) {
                s[i] = '1';
                carry = 0; // Carry is consumed
                break;
            }
        }

        if (carry == 1) {
            return '1' + s;
        }

        return s;
    }
    int numSteps(string s) {
        int c = 0;
        
        while (s != "1"){

            if (s.back() == '0'){ // matlab num is even so, pop back and count me add one kro
                s.pop_back();
            }
            else{
                // agar nhi toh matlab number is odd so, s me one add karo.

                s = addOne(s);

            }

            c+=1;

        }

        return c;
    }
};


int main(){
    Solution obj;

    string s;

    cin >> s;

    cout << obj.numSteps(s);

    return 0;
}