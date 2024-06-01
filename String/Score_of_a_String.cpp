#include<iostream>

using namespace std;


class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        for (int i=1; i<s.length(); i++){
            ans += abs(s[i] - s[i-1]);
        }
        return ans;
    }
};

int main(){
    Solution obj;
    string s;
    cin >> s;
    cout << obj.scoreOfString(s) << endl;
    return 0;
}