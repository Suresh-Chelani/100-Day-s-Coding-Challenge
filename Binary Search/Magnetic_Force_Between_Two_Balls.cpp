#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool Possible(int &force, vector<int>& position, int& m){
        int prv = position[0];
        int count = 1;
        for (int i=1; i<position.size(); i++){
            int curr = position[i];
            if (curr - prv >= force){
                count += 1;
                prv = curr;
            }
            if (count == m) break;
        }

        return count == m;
    }    

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int s = 1;
        int n = position.size();
        int e = position[n-1] - position[0];

        int ans = 0;

        while (s <= e){
            int mid = s + (e - s)/2;
            if (Possible(mid, position, m)){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        
        return ans;
    }
};