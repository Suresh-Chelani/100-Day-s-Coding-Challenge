#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

class Solution
{
    public:
    //Function to find all possible unique subsets.
    // Time: (2^n * n (log n))
    // Space: (n * 2^n)
    set<vector<int>>ans;
    void solve(vector<int>& arr, vector<int>& curr, int i){
        
        if (arr.size() == i){
            ans.insert(curr);
            return ;
        }
        
        curr.push_back(arr[i]);
        solve(arr, curr, i+1);
        curr.pop_back();
        
        solve(arr, curr, i+1);
        
    }
    vector<vector<int>> AllSubsets(vector<int> arr, int n)
    {
        vector<int>curr;
        sort(arr.begin(), arr.end());
        vector<vector<int>>an;
        solve(arr,curr, 0);
        
        for (auto &vec: ans){
            an.push_back(vec);
        }
        
        return an;
    }
};

class Solution1 {
    public:
    //Function to find all possible unique subsets.
    // Time: (2^n * n)
    // Space: (n * 2^n)
    vector<vector<int>> ans;
    void solve(int i, vector<int>& arr, vector<int>& empty) {
    
        ans.push_back(empty);

        for (int j = i; j < arr.size(); j++) {
            if (j > i && arr[j-1] == arr[j]) continue; // Skip duplicates
            empty.push_back(arr[j]);
            solve(j + 1, arr, empty);
            empty.pop_back();
        }   
    }

    vector<vector<int>> AllSubsets(vector<int> arr, int n)
    {
        vector<int>curr;
        sort(arr.begin(), arr.end());
        solve(0, arr, curr);
        
        return ans;
    }


};

int main(){
    Solution obj;
    Solution1 obj1;
    int n; 

    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];
    
    vector<vector<int>> ans = obj1.AllSubsets(arr,n);

    for (int i=0; i<ans.size(); i++){
        for (int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}

/*

*/