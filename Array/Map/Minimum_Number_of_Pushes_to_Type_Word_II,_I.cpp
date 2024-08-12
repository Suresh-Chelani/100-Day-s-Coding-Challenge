class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for (char ch: word) freq[ch-'a']++;
        sort(freq.begin(), freq.end(), greater<int>());
        
        int ans = 0;
        int count = 0;
        for (int i=0; i<26; i++){
            int val = freq[i]*(i/8+1);
            ans += val;
        }

        return ans;
    }
};

// aabbccddeeffgghhiiiiii

// i -> 6
// a -> 2, b -> 2, c -> 2, d -> 2, e -> 2, f -> 2, g -> 2, h-> 2
