class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int dx[4]= {0, 1, 0, -1};
        int dy[4]= {1, 0, -1, 0};
        int step = 0;
        int dir = 0;
        vector<vector<int>>ans = {{rStart, cStart}};

        while (ans.size() < rows*cols){
            if (dir == 0 || dir == 2) step++;

            for (int i=0; i<step; i++){
                rStart += dx[dir];
                cStart += dy[dir];

                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                    ans.push_back({rStart, cStart});
            }
            dir = (dir + 1) % 4;
        }

        return ans;
    }
};


// [1 * 4] =>  [0, 0, 0, 0]

// [2,3,4,5]
// [3,4,5,3]
// [4,5,6,2]
