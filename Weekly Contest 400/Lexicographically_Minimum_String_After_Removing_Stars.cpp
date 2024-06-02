#include <iostream>
#include <vector>
#include <queue>

using namespace std;



class Solution {
public:
    typedef pair<char, int> P;
    struct cmp{
        bool operator()(P &p1, P &p2){
            if (p1.first == p2.first)
                return p1.second < p2.second;

            return p1.first > p2.first;
        }
    };
    string clearStars(string s) {
        priority_queue<P, vector<P>, cmp> pq;
        string ans = "";
        int n = s.length();
        for (int i=0; i<n; i++){
            if (s[i] != '*'){
                pq.push({s[i], i});
            }
            else{
                int indx = pq.top().second;
                pq.pop();
                s[indx] = '*';
            }
        }


        for (int i=0; i<n; i++){
            if (s[i] != '*')
                ans += s[i];
        }

        return ans; 
    }
};


int main(){
    Solution obj;

    string s;

    cin >> s;

    cout << obj.clearStars(s);

    return 0;
}