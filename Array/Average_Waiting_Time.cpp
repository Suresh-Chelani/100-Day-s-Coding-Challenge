#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        int n = customers.size();
        double waiting = customers[0][1];
        double total = customers[0][0] + waiting;
        for (int i = 1; i < n; i++)
        {
            if (total < customers[i][0])
            {
                waiting += customers[i][1];
                total = customers[i][0] + customers[i][1];
            }
            else
            {
                total += customers[i][1];
                waiting += (total - customers[i][0]);
            }
        }

        return waiting / n;
    }
};