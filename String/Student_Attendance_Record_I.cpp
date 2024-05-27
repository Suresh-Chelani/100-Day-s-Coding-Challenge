#include <iostream>


using namespace std;


class Solution {
public:
    bool checkRecord(string s) {
        int abs = 0;
        int n = s.length();
        for (int i=0; i<n; i++){
            if (s[i] == 'A') abs++;
            if (i+2 < n && s[i] == 'L' && s[i+1] == 'L' && s[i+2] == 'L') return false;
            if (abs >= 2) return false;
        }

        return true;
    }
};



int main(){
    
    Solution obj;

    string s;

    cin >> s;

    if (obj.checkRecord(s))  cout << "True";
    else cout << "False";

    return 0;
}