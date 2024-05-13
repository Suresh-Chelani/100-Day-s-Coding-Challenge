#include<iostream>

using namespace std;

string isPalindrom(int i, int j, string& s){
    
    if (i >= j) return "True";

    if (s[i] != s[j]) return "False";

    return isPalindrom(i+1, j-1, s);
}
int main(){

    string s;
    cin >> s;
    int i=0 , j = s.length()-1;
    cout << isPalindrom(i, j, s) << endl;
    return 0;
}