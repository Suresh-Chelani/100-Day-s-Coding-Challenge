#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixXOR(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        }

        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k < n; ++k) {
                if (prefixXOR[i] == prefixXOR[k + 1]) {
                    count += (k - i);
                }
            }
        }

        return count;
    }
};


int main(){
    Solution obj;
    int n; 
    cin >> n;
    vector<int>arr(n);

    for (int i=0; i<n; i++) cin >> arr[i];

    cout << obj.countTriplets(arr) << endl;
}