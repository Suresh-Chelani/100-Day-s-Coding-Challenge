#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

class Solution {
public:
   int n;
   bool check(vector<int>& hand, int groupSize, int i) {
        int next = hand[i] + 1;
        hand[i] = -1;  
        int count = 1;
        i += 1;
        while (i < n && count < groupSize) {
            if (hand[i] == next) {
                next = hand[i] + 1;
                hand[i] = -1;
                count++;
            }
            i++;
        }
        return count == groupSize;
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        n = hand.size();
        if (n % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        for (int i = 0; i < n; i++) {
            if (hand[i] >= 0) {
                if (!check(hand, groupSize, i)) return false;
            }
        }
        return true;
    }
};

int main(){
    Solution obj;
    int n;
    cin >> n;
    int groupSize;
    cin >> groupSize;
    vector<int>hand(n);
    for (int i=0; i<n; i++) cin >> hand[i];
    cout << obj.isNStraightHand(hand,groupSize);
    return 0;
}