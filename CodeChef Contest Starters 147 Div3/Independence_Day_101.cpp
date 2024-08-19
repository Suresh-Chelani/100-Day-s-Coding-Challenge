#include <iostream>
using namespace std;

int main() {
    int t;
    
    cin >> t;
    
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        
    
        int max_count = max({a, b, c});
        int total = a + b + c;
        
    
        if (max_count <= (total + 1) / 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

}
