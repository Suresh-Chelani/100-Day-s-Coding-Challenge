#include<iostream>
#include<vector>
using namespace std;


// Print all the subsequence of the array.

void PrintSubsequence(int i, vector<int>& arr, vector<int> empty){

    if (i >= arr.size()){
        for (int val: empty) cout << val << " ";
        if (!empty.size()) cout << "{}";
        cout << endl;
        return ;
    }

    // take the element from the arr
    empty.push_back(arr[i]);
    PrintSubsequence(i+1, arr, empty);
    empty.pop_back(); // pop or remove the last element,  for "not take" condition...

    // not take the element from the arr
    PrintSubsequence(i+1, arr, empty);
}


/*



We can also "not pick" first, then pick the element from the array by that code
and our output is just in reverse order

void PrintSubsequence(int i, vector<int>& arr, vector<int> empty){

    if (i >= arr.size()){
        for (int val: empty) cout << val << " ";
        if (!empty.size()) cout << "{}";
        cout << endl;
        return ;
    }

    
    // not take the element from the arr
    PrintSubsequence(i+1, arr, empty);

    // take the element from the arr
    empty.push_back(arr[i]);
    PrintSubsequence(i+1, arr, empty);
    empty.pop_back(); // pop or remove the last element,  for "not take" condition...
}



*/

int main(){

    int n;
    cin >> n;
    
    vector<int>arr(n);

    for (int i=0; i<n; i++) cin >> arr[i];

    PrintSubsequence(0,arr, {});

    return 0;
}

// Time: O(2^n * n) , Space: O(n)