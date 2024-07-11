#include <iostream>
#include<vector>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for (char ch: s){
            if (ch == ')'){
                string curr = "";
                while (!st.empty() && st.top() != '('){
                    curr += st.top();
                    st.pop();
                }
                if (st.top() == '(') st.pop();

                for (char c : curr) st.push(c);
            }
            else{
                st.push(ch);
            }
        }

        string ans = "";

        while (!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};