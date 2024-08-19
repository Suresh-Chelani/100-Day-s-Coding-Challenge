
#include <iostream>
#include <vector>

using namespace std;

int maximumSum(long long n, vector<int> &v) {
    int mx_sum = 0;

    for (long long i=0; i<n; i++){
        if (v[i] > 0){
            mx_sum += v[i]*2;
        }
        else{
            mx_sum += v[i]/2;
        }
    }

    return mx_sum;

}