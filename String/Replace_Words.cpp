#include <iostream>
#include <vector>
#include <sstream>
// #include <unordered_set>

using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        vector<string>words;
        string curr = "";
        for (char ch: sentence){
            if (ch == ' '){
                words.push_back(curr);
                curr = "";
            }
            else{
                curr += ch;
            }
        }
        words.push_back(curr);
        for (const string& dt : dict) {
            int len = dt.length();
            for (int i = 0; i < words.size(); i++) {
                if (dt == words[i].substr(0, len)) {
                    words[i] = dt; 
                }
            }
        }
        curr = "";

        for (int i=0; i<words.size(); i++){
            if (i==words.size()-1){
                curr += words[i];
                break;
            }
            curr += words[i] + " ";
        }

        return curr;
    }
};

int main(){

    Solution obj;

    int n;
    string s;

    cin >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++) {
        cin >> dict[i];
    }
    cin.ignore(); 
    getline(cin, s);

    string ans = obj.replaceWords(dict, s);
    cout << ans;

    return 0;
}