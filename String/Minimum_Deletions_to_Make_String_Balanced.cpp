class Solution {
public:
    int minimumDeletions(string s) {
        int total_a = 0;
        for (char c : s) {
            if (c == 'a') total_a++;
        }
        
        int min_deletions = total_a;
        int count_b = 0;
        int count_a = total_a;
        
        for (char c : s) {
            if (c == 'a') {
                count_a--;
            } else {
                count_b++;
            }
            min_deletions = min(min_deletions, count_a + count_b);
        }
        
        return min_deletions;
    }
};
