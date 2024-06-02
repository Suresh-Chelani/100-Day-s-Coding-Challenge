#include <iostream>

using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0;
        int e = 0;
        for (char ch: s){
            if (ch == 'E') e++;
            else e--;
            ans = max(ans, e);
        }
        return ans;
    }
};

int main(){
    Solution obj;
    string s;
    cin >> s;
    cout << obj.minimumChairs(s) << endl;
}