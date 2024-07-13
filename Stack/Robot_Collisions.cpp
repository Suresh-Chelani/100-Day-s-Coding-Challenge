#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <numeric>

using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        int n = healths.size();
        vector<int> actual_index(n);
        iota(actual_index.begin(), actual_index.end(), 0); // it store the value from 0 to arr.size() - 1

        auto lambda = [&](int &i, int &j) { // it is for sorting the actual index of positions of robots
            return positions[i] < positions[j];
        };

        sort(actual_index.begin(), actual_index.end(), lambda);

        vector<int> ans;
        stack<int> st;

        for (int curr_index : actual_index)
        { // simple simulation using the stack..
            if (directions[curr_index] == 'R')
                st.push(curr_index);
            else
            {
                while (!st.empty() && healths[curr_index] > 0)
                {

                    int top_index = st.top();
                    st.pop();

                    if (healths[curr_index] > healths[top_index])
                    {
                        healths[top_index] = 0;
                        healths[curr_index] -= 1;
                    }
                    else if (healths[curr_index] < healths[top_index])
                    {
                        healths[top_index] -= 1;
                        healths[curr_index] = 0;
                        st.push(top_index);
                    }
                    else
                    {
                        healths[top_index] = 0;
                        healths[curr_index] = 0;
                    }
                }
            }
        }

        for (int val : healths)
        {
            if (val > 0)
                ans.push_back(val);
        }

        return ans;
    }
};