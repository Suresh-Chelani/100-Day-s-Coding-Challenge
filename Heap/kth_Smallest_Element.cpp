#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        for (int &val: arr){
            pq.push(val);
            if (pq.size() > k){
                pq.pop();
            }
        }
        int ans = pq.top();
        return ans;
    }
};
