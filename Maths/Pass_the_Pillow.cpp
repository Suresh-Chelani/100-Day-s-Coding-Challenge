#include <iostream>
using namespace std;

class Solution
{
public:
    int passThePillow(int n, int time)
    {
        int round = time / (n - 1);
        int rem = time % (n - 1);

        if (round % 2 == 0)
            return rem + 1; // right direction

        return n - rem; // left direction
    }
};