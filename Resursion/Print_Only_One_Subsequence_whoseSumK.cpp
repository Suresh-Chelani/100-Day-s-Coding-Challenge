#include<iostream>
#include<vector>
using namespace std;


// Print only one subsequence whose sum equal to k.

bool Subsequence(int i, vector<int>& arr, int sum, vector<int> empty , int k){

    if (i >= arr.size()){
        // condition true then return the answer to the calling function 
        if (sum == k){
            for (int val: empty) cout << val << " ";
            cout << endl;

            return true;
        }

        return false;
    }
    sum += arr[i];
    empty.push_back(arr[i]);
    //  if this function give true then no need to further calling 
    if (Subsequence(i+1, arr, sum, empty, k)) 
        return true;
    sum -= arr[i];
    empty.pop_back();
    //  Same of this function, if it give true then no need to further calling
    if (Subsequence(i+1, arr, sum, empty, k))
        return true;

    return false;
}

int main(){

    int n, k;
    cin >> n >> k;
    
    vector<int>arr(n);

    for (int i=0; i<n; i++) cin >> arr[i];

    Subsequence(0,arr,0, {}, k);

    return 0;
}