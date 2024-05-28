#include <iostream>
#include <vector>

using namespace std;


// Time: O(n) and space: O(1)
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        int j = 0;
        int curr = 0;
        for (int i=0; i < s.length(); i++){
            curr += abs(s[i] - t[i]);
            while (curr > maxCost){
                curr -= abs(s[j]- t[j]);
                j++;
            }

            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};


// Time: O(n^2) and space: O(n)
// class Solution {
// public:
//     int equalSubstring(string s, string t, int maxCost) {
//         vector<int>cost;

//         for (int i=0; i<s.length(); i++){
//             cost.push_back(abs(s[i] - t[i]));
//         }
//         int ans = 0;
//         for (int i=0; i<cost.size(); i++){
//             int curr = 0;
//             int j = i;
//             while (j < cost.size() && curr + cost[j] <= maxCost){
//                 curr += cost[j++];
//                 ans = max(ans, j - i);
//             }
//         }

//         return ans;
//     }
// };

int main(){
    Solution obj;
    string s, t;
    cin >> s >> t;
    int mx;
    cin >> mx;

    cout << obj.equalSubstring(s, t, mx);

    return 0;
}