#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:

    bool isSave(int i, int j, vector<vector<int>>& board, int n){
        // row me check karna hai save hai ki nhi

        int row = i;
        int col = j;

        for (int k = 0; k < col; k++){
            if (board[row][k] == 1) 
                return false;
        }


        // digonal me check karna hai save for upper side..

        row = i;
        col = j;
        while (row >= 0 && col >= 0){
            if (board[row][col] == 1) return false;

            row--;
            col--;
        }

        // digonal me check karna hai save for lower side..

        row = i;
        col = j;
        while (row < n && col >= 0){
            if (board[row][col] == 1) return false;

            row++;
            col--;
        }

        return true;
    }

    void addAnswer(vector<vector<int>>& arr, vector<vector<int>>& board, int n){
        
        vector<int>temp;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                temp.push_back(board[i][j]);
            }
        }
        arr.push_back(temp);
    }

    void halper(int col, vector<vector<int>>& board, vector<vector<int>>& arr, int& n){

        if (n == col){
            addAnswer(arr, board, n);
            return ;
        }
        for (int row = 0; row < n; row++){
            if (isSave(row,col, board, n)){
                board[row][col] = 1;
                halper(col+1, board, arr, n);
                board[row][col] = 0;
            }
        }

    }
    vector<vector<int>> solve(int n){

        vector<vector<int>>board(n,vector<int>(n, 0));

        vector<vector<int>>arr;

        halper(0, board, arr, n); 

        return arr;
    }
    
};


int main(){

    Solution obj;
    
    int N;

    cin >> N;

    vector<vector<int>> arr = obj.solve(N);

    if (!arr.empty()) {
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found." << endl;
    }

    

    return 0;
}

// /*
// NQueens: 


//     [     0 1 2 3
//        0 [0 Q 0 0]
//        1 [0 0 0 Q]
//        2 [Q 0 0 0]
//        3 [0 0 Q 0]
//     ]


// done yesterday POTD data: 19 may 