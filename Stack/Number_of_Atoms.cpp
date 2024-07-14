#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;

class Solution
{
public:
    string countOfAtoms(string formula)
    {
        map<string, int> countMap;
        stack<map<string, int>> stack;
        int i = 0;
        int n = formula.size();

        while (i < n)
        {
            if (formula[i] == '(')
            {
                stack.push(countMap);
                countMap.clear();
                i++;
            }
            else if (formula[i] == ')')
            {
                int j = i + 1;
                while (j < n && isdigit(formula[j]))
                    j++;
                int multiplier = (j == i + 1) ? 1 : stoi(formula.substr(i + 1, j - i - 1));
                i = j;

                if (!stack.empty())
                {
                    map<string, int> topMap = stack.top();
                    stack.pop();
                    for (auto &pair : countMap)
                    {
                        topMap[pair.first] += pair.second * multiplier;
                    }
                    countMap = move(topMap);
                }
            }
            else
            {
                int j = i + 1;
                while (j < n && islower(formula[j]))
                    j++;
                string element = formula.substr(i, j - i);
                i = j;

                while (j < n && isdigit(formula[j]))
                    j++;
                int count = (j == i) ? 1 : stoi(formula.substr(i, j - i));
                i = j;

                countMap[element] += count;
            }
        }

        string result;
        for (auto &pair : countMap)
        {
            result += pair.first;
            if (pair.second > 1)
                result += to_string(pair.second);
        }

        return result;
    }
};