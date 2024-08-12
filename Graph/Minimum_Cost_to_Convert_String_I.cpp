class Solution {
public:

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        int n = cost.size();
        vector<vector<long long>> v(26, vector<long long>(26, INT_MAX));
        for(int i = 0; i < 26; i++) v[i][i] = 0;
        for(int i = 0; i < n; i++){
            int k = v[original[i] - 'a'][changed[i] - 'a'];
            v[original[i] - 'a'][changed[i] - 'a'] = min(k, cost[i]);
        }

        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if( v[i][j] > (v[i][k] + v[k][j])){
                            v[i][j] = v[i][k] + v[k][j];
                        }
                }
            }
        }

        long long ans = 0;
        for(int i = 0; i < source.size(); i++){
            long long k = v[source[i] - 'a'][target[i] - 'a'];
            if(k == INT_MAX) return -1;
            ans += k;
        }

        return ans;
    }
};
