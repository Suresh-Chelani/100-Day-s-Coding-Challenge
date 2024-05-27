#include <iostream>
#include<vector>

using namespace std;



// Time: Catalan number -> O(c(n)) => O(4^n/root n) and Space: O(4^n * root 2)
class Solution {
public:
    vector<string> ans;

    void solve(string& curr, int open, int close, int n) {
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            solve(curr, open + 1, close, n);
            curr.pop_back();
        }

        if (close < open) {
            curr.push_back(')');
            solve(curr, open, close + 1, n);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr, 0, 0, n);
        return ans;
    }
};


// Time: O(2^2n * 2n) and Space: O(2n)
/*
class Solution {
public:
    vector<string>ans;
    bool isValid(string s){
        int c = 0;

        for (char ch: s){
            if (ch == '(') c+=1;
            else  c-= 1;
            if (c < 0) return false;
        }

        return c == 0;
    }
    void solve(string& curr, int n){
        if (2*n == curr.length()){
            if (isValid(curr)){
                ans.push_back(curr);
            }
            return ;
        }

        curr.push_back('(');
        solve(curr, n);
        curr.pop_back();
        
        curr.push_back(')');
        solve(curr, n);
        curr.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr, n);

        return ans;
    }
};

*/

int main(){

    Solution obj;

    vector<string> ans = obj.generateParenthesis(2);

    for (string s: ans){
        cout << s << " ";
    }
    return 0;
}