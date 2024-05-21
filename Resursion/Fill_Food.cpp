#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int n, m;
    void dfs(vector<vector<int>>& ans, int sr, int sc, int newColor, vector<vector<int>>& image, int ini){
        ans[sr][sc] = newColor;
        
        for (int k=0; k<4; k++){
            int new_i = sr + dx[k];
            int new_j = sc + dy[k];
            
            if (new_i < n && new_i >= 0 && new_j < m && new_j >= 0 && image[new_i][new_j] == ini && ans[new_i][new_j] != newColor){
                dfs(ans,new_i, new_j, newColor, image, ini);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();
        int ini = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(ans, sr,sc, newColor, image, ini);
        return ans;
    }
};

int main(){
    Solution obj;
    int n, m;
    cin >> n >> m;

    int x, y;
    cin >> x >> y;

    int newC;

    cin >> newC;

    vector<vector<int>>img(n, vector<int>(m));

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> img[i][j];
        }
    }   
 
    img = obj.floodFill(img, x, y, newC);
 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << img[i][j] << " ";
        }
        cout << endl;
    }
 
    return 0;
}