#include<iostream>
#include<vector>

using namespace std;
// Reverse the Array using recursion

void ReverseArray(int start, int end, vector<int>& arr){
    if (start >= end) return;
    swap(arr[start], arr[end]);
    ReverseArray(start+1,end-1,arr);
}

int main(){
    
    int n; 
    cin >> n; 
    vector<int>arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];
    int s = 0, e = n-1;
    ReverseArray(s, e, arr);
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;    
}