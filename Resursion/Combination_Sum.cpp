#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>ans;
void CombinationSum(int i, vector<int>& arr, vector<int> empty, int target){

    if (i == arr.size()) {
        if (target == 0)
        ans.push_back(empty);
        return ;
    }

    if (arr[i] <= target) {
        empty.push_back(arr[i]);
        CombinationSum(i, arr, empty, target - arr[i]);
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

    for (int i=0; i<ans.size(); i++){
        for (int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}