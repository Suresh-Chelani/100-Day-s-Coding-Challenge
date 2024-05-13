#include<iostream>
#include<vector>
using namespace std;


// Print all the subsequence whose sum equal to k.

void Subsequence(int i, vector<int>& arr, int sum, vector<int> empty , int k){

    if (i >= arr.size()){
        if (sum == k){
            for (int val: empty) cout << val << " ";
            cout << endl;
        }

        return ;
    }
    sum += arr[i];
    empty.push_back(arr[i]);
    Subsequence(i+1, arr, sum, empty, k);
    sum -= arr[i];
    empty.pop_back();

    Subsequence(i+1, arr, sum, empty, k);

}

int main(){

    int n, k;
    cin >> n >> k;
    
    vector<int>arr(n);

    for (int i=0; i<n; i++) cin >> arr[i];

    Subsequence(0,arr,0, {}, k);

    return 0;
}