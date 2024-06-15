#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>arr;
        int n = profits.size();
        for (int i=0; i<n; i++){
            arr.push_back({capital[i], profits[i]});
        }

        sort(arr.begin(), arr.end());

        priority_queue<int> maxHeap;
        int i=0;
        while (k--){
            while (i < n && arr[i].first <= w){
                maxHeap.push(arr[i].second);
                i++;
            }

            if (maxHeap.empty()) return w;

            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};