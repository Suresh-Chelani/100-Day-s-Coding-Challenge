#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int c = 0;
        for (string s : logs)
        {
            if (c > 0 && s == "../")
            {
                c -= 1;
            }
            else if (s != "./" && s != "../")
            {
                c += 1;
            }
        }
        return c;
    }
};

/*

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int>st;
        for (string s: logs){
            if (!st.empty() && s == "../"){
                st.pop();
            }
            else if (s != "./" && s != "../"){
                st.push(1);
            }
        }
        return st.size();
    }
};

*/