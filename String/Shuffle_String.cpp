#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
       int n = s.length();
       vector<char>nl(n);
       for (int i=0; i<n; i++){
            nl[indices[i]] = s[i];
       } 
       string ans = "";
       for (char ch: nl){
        ans += ch;
       }

       return ans;
    }   
};


int main(){
    Solution obj;
    string s;
    cin >> s;
    vector<int>idx(s.length());
    for (int i=0; i<s.length(); i++) cin >> idx[i];
    cout << obj.restoreString(s,idx) << endl;
    return 0;
}