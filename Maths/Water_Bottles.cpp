#include <iostream>

using namespace std;

// Iterative Simulation

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = numBottles;
        while (numBottles >= numExchange)
        {
            int drink = numBottles / numExchange;
            ans += drink;
            int rem = (numBottles % numExchange);
            numBottles = drink + rem;
        }
        return ans;
    }
};

/*

Math + Simulation

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};

*/