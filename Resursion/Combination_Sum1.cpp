#include<iostream>
#include<vector>
#include <set>
#include<algorithm>
using namespace std;


// set<vector<int>>ans;
// void CombinationSum1(int i, vector<int>& arr, vector<int> empty, int target){

//     if (i == arr.size()) {
//         if (target == 0){
//         sort(empty.begin(),empty.end());
//         ans.insert(empty);
//         }
//         return ;
//     }

//     if (arr[i] <= target) {
//         empty.push_back(arr[i]);
//         CombinationSum1(i+1, arr, empty, target - arr[i]);
//         empty.pop_back();
//     }
//     CombinationSum1(i+1, arr, empty, target);

// }

// int main(){

//     int n, target;

//     cin >> n >> target;

//     vector<int>arr(n);

//     for (int i=0; i<n; i++) cin >> arr[i];
//     CombinationSum1(0, arr, {}, target);

//     vector<vector<int>>arr1;

//     for (auto &val: ans){
//         arr1.push_back(val);
//     }

//     for (int i=0; i<arr1.size(); i++){
//         for (int j=0; j<arr1[i].size(); j++){
//             cout << arr1[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

vector<vector<int>> ans;

void CombinationSum1(int i, vector<int>& arr, vector<int> empty, int target) {
    if (target == 0) {
        ans.push_back(empty);
        return;
    }

    for (int j = i; j < arr.size(); j++) {
        if (j > i && arr[j-1] == arr[j]) continue; // Skip duplicates
        if (arr[j] > target) break; // No point in continuing if arr[j] is greater than the remaining target
        empty.push_back(arr[j]);
        CombinationSum1(j + 1, arr, empty, target - arr[j]);
        empty.pop_back();
    }   
}

int main() {
    int n, target;

    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end()); // Sort the array to handle duplicates and make the algorithm efficient
    CombinationSum1(0, arr, {}, target);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
