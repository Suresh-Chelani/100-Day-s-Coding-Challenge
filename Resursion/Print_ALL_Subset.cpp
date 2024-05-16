#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
    public:
    int n;
    void solve(vector<int>& A, int i, vector<vector<int> >& ans, vector<int>& curr){
        if (i == n){
            ans.push_back(curr);
            return ;
        }
        // Include the current element in the subset
        curr.push_back(A[i]);
        solve(A, i + 1, ans, curr);
        curr.pop_back(); //Remove the current element from the subset and explore further

        // Exclude the current element from the subset
        solve(A, i + 1, ans, curr);
    }
    vector<vector<int>> subsets(vector<int>& A)
    {
        n = A.size();
        vector<vector<int>> ans;
        vector<int>curr;
        solve(A, 0, ans, curr);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution obj;
    int n; 

    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];
    
    vector<vector<int>> ans = obj.subsets(arr);

    for (int i=0; i<ans.size(); i++){
        for (int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}