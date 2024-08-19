#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;


bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

unordered_set<int> precomputeNonPrimes() {
    unordered_set<int> nonPrimes;
    for (int i = 2; i <= 200; ++i) {
        if (!isPrime(i)) {
            nonPrimes.insert(i);
        }
    }
    return nonPrimes;
}

int main() {
    int T;
    cin >> T;

    unordered_set<int> nonPrimes = precomputeNonPrimes();

    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        map<int,int>mp;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            mp[A[i]] = i;
        }
        
        
        bool found = 0;
        for (int i = 0; i < N; ++i) {
            int first = A[i];
            
            for (int j=1; j <= 100; j++){
               
               if (nonPrimes.find(first+j)!=nonPrimes.end() && mp.find(j)!=mp.end() && i != mp[j]){
                   cout << i+1 << " " << mp[j]+1 << endl;
                   found = 1;
                   break;
               }
                
            }
            if (found) break;
        }
        
        if (!found) cout << -1 << endl;

    }

    return 0;
}
