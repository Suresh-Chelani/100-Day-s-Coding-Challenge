#include<iostream>
#include<vector>
#include <set>
#include<algorithm>
using namespace std;

// Combination Sum 1

set<vector<int>>ans;
void CombinationSum(int i, vector<int>& arr, vector<int> empty, int target){

    if (i == arr.size()) {
        if (target == 0){
        sort(empty.begin(),empty.end());
        ans.insert(empty);
        }
        return ;
    }

    if (arr[i] <= target) {
        empty.push_back(arr[i]);
        CombinationSum(i+1, arr, empty, target - arr[i]);
        empty.pop_back();
    }
    CombinationSum(i+1, arr, empty, target);

}

int main(){

    int n, target;

    cin >> n >> target;

    vector<int>arr(n);

    for (int i=0; i<n; i++) cin >> arr[i];
    CombinationSum(0, arr, {}, target);

    vector<vector<int>>arr1;

    for (auto &val: ans){
        arr1.push_back(val);
    }

    for (int i=0; i<arr1.size(); i++){
        for (int j=0; j<arr1[i].size(); j++){
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}