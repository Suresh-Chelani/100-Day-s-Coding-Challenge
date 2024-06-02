#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        for (const auto& interval : intervals) {
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        int meetingDay = 0;

        for (int i = 0; i < merged.size(); i++){
            meetingDay += (merged[i][1] - merged[i][0]) + 1;
        }

        return days - meetingDay; 
    }
};

int main(){
    Solution obj;
    int day;
    cin >> day;
    int n;
    cin >> n;
    vector<vector<int>>interval(n, vector<int>(2));
    
    for (int i=0; i<n; i++) cin >> interval[i][0] >> interval[i][1];

    cout << obj.countDays(day, interval) << endl;

    return 0;
}