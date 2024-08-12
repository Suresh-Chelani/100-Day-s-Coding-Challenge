// Using Nested loops

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                for (int k=j+1; k<n; k++){
                    if ((rating[i] < rating[j] && rating[j]  < rating[k]) || 
                        (rating[i] > rating[j] && rating[j]  > rating[k])) 
                        ans++;
                }
            }
        }

        return ans;
    }
};


// Using Map

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        unordered_map<int,int>mp_inc, mp_dec;

        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                if (rating[i] < rating[j]){
                    mp_inc[rating[i]]++;
                }
                else if(rating[i] > rating[j]){
                    mp_dec[rating[i]]++;
                }
            }
        }
    
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                if (rating[i] < rating[j]){
                    ans += mp_inc[rating[j]];
                }
                else if (rating[i] > rating[j]){
                    ans += mp_dec[rating[j]];
                }
            }
        }

        return ans;
    }
};


// [2,5,3,4,1]
//     inc   dec    ans
// 2 -> 3    1      (2, 5 -> 0) 0
// 5 -> 0    3       (2, 3 -> 1) = 1
// 3 -> 1    1       (2, 4)
// 4 -> 0    1
// 1 -> 0    0
