#include<iostream>

using namespace std;

int Nthfibonacci(int n){
    if (n <= 1) return 1;

    return Nthfibonacci(n-1)+Nthfibonacci(n-2);
}
int main(){

    int n;

    cin >> n;

    cout << Nthfibonacci(n) << endl;
    return 0;
}