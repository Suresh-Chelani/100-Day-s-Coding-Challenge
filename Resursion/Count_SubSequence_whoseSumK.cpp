#include<iostream>
#include<vector>
using namespace std;


// count the subsequences whose sum equal to k.

int Subsequence(int i, vector<int>& arr, int sum, int k){

    if (i >= arr.size()){
        // condition true then return 1 for achiving the one subarray 
        if (sum == k){
            return 1;
        }

        return 0;
    }
    sum += arr[i];
    // if pick condition is ture or flase save it to l 
    int l = Subsequence(i+1, arr, sum, k);

    sum -= arr[i];
    // if not pick condition is ture or flase save it to r 
    int r = Subsequence(i+1, arr, sum, k);

    return l + r; // add the both l and r then return the answer to further calling function why add for count the subarray which give 1.
}

int main(){

    int n, k;
    cin >> n >> k;
    
    vector<int>arr(n);

    for (int i=0; i<n; i++) cin >> arr[i];

    cout << Subsequence(0,arr,0, k) << endl;

    return 0;
}