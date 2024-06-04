#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int longestPalindrome(string s) {   
        unordered_map<char,int>mp;
        for (char ch: s){
            mp[ch]+=1;
        }

        int even = 0;
        bool odd = false;
        for (auto &item: mp){
            if (item.second%2==0){
                even += item.second;
            }
            else{
                odd = true;
                even += item.second - 1;
            }
        }

        return odd == true ? even + 1 : even;
    }
};

int main(){
    Solution obj;
    string s;
    cin >> s;
    cout << obj.longestPalindrome(s) << endl;
    return 0;
}