#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> ans;

void PrintCombinations(int i, vector<int>& empty, int k, int N){
    if (k == 0){
        ans.push_back(empty);
        return ;
    }
    if (i > N) return ;
    empty.push_back(i); // take_it element
    PrintCombinations(i+1, empty, k-1, N);  // and explore others
    empty.pop_back();   // pop that element or not take it
    PrintCombinations(i+1, empty, k, N); // explore others 
}

int main(){

    int n, k;
    cin >> n >> k;  

    vector<int> curr;

    PrintCombinations(1, curr, k, n); 

    for (int i=0; i<ans.size(); i++){
        for (int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
