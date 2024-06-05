#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> ans(26, INT_MAX); 
        for (int i = 0; i < words.size(); i++) {
            vector<int> freq(26, 0);
            for (char ch : words[i]) {
                freq[ch - 'a']++;
            }

            for (int j = 0; j < 26; j++) {
                ans[j] = min(ans[j], freq[j]);
            }
        }

        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (ans[i]-- > 0) {
                result.push_back(string(1, i + 'a'));
            }
        }

        return result;
    }
};

int main(){
    Solution obj;
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];  
    vector<string> ans = obj.commonChars(words);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}
