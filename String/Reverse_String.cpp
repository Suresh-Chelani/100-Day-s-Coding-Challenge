#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size()-1;
        while (i < j) swap(s[i++], s[j--]);   
    }
};

int main(){
    Solution obj;
    int n;
    cin >> n;
    vector<char> s(n);
    for (int i=0; i<n; i++) cin >> s[i];
    obj.reverseString(s);
    for (int i=0; i<n; i++) cout << s[i] << " ";
    return 0;
}