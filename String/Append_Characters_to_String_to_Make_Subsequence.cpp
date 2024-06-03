#include <iostream>
#include <string>

using namespace std;


class Solution {
    public:

    int appendCharacters(string s, string t) {
        int i = 0, j = 0;

        while (i < s.length() && j < t.length()){
            if (s[i] == t[j]){
                i++;
                j++;
            }
            else if (s[i] != t[j]){
                i++;
            }
        }

        return t.length() - j;
    }
};


int main(){
    Solution obj;
    string s = "", t = "";
    cin >> s >> t;

    cout << obj.appendCharacters(s, t) << endl;

    return 0;
}