#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ans;
    unordered_set<string> check;
    
    void solve(int i, string currSentence, string& s) {
        if (i >= s.length()) {
            ans.push_back(currSentence);
            return;
        }

        for (int j = i; j < s.length(); j++) {
            string str = s.substr(i, j - i + 1);
            if (check.find(str) != check.end()) {
                string md = currSentence;

                if (!currSentence.empty()) {
                    currSentence += ' ';
                }

                currSentence += str;
                solve(j + 1, currSentence, s);

                currSentence = md;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string st : wordDict) check.insert(st);

        solve(0, "", s);

        return ans;
    }
};

int main() {
    Solution solution;
    string s;
    int n;
    vector<string> wordDict;

    cout << "Enter the string: ";
    cin >> s;

    cout << "Enter the number of words in the dictionary: ";
    cin >> n;

    wordDict.resize(n);
    cout << "Enter the words in the dictionary:\n";
    for (int i = 0; i < n; i++) {
        cin >> wordDict[i];
    }

    vector<string> results = solution.wordBreak(s, wordDict);

    cout << "Possible sentences are:\n";
    for (const string& sentence : results) {
        cout << sentence << endl;
    }

    return 0;
}
