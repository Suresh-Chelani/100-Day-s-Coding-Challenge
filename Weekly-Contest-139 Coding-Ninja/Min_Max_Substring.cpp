
#include <iostream> 
#include<vector>

using namespace std;

string getmax(int n, string &s) {
    string mx = "";
    int mx_l = 1;
    int curr_l = 1;
    string curr = "";
    for (int i=0; i<n-1; i++){
        if (s[i] <= s[i+1]){
            curr += s[i];
            curr_l += 1;
        }
        else{
            curr += s[i];
            if (mx_l < curr_l){
                mx_l = curr_l;
                mx = curr;
            }
            curr = "";
            curr_l = 1;
        }
    }

    curr += s[n-1];
    if (mx_l < curr_l){
        mx = curr;
    }  

    return mx;

}

int maxIncLen(string& s){
    int n = s.length();
    vector<int>dp(n,1);
    int mx = 1;

    for (int i=1; i<n; i++){
        if (s[i] >= s[i-1]){
            dp[i] = dp[i-1]+1;
    
        }
        mx = max(mx, dp[i]);
    }

    return mx;
}

int minimumOfMaximum(int n, string& s){

    int inl = maxIncLen(s);
    int mn = inl;

    for (int i=0; i<n-1; i++){
        swap(s[i], s[i+1]);
        int new_mx = maxIncLen(s);
        mn = min(mn, new_mx);
        swap(s[i], s[i+1]);
    }

    return mn;
}



// aabbaabb = 3

// aaaabbbb = 4

// It is not optimized give TLE
