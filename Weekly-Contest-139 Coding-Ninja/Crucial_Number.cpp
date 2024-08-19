#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checkcrucial(int& num){
   string s = to_string(num);

   for (char& ch: s){
      int val = ch - '0';
      if (val != 0 && num % val == 0) return true;
   }

   return false;
}

int crucialNumber (int n) {
   
   for (int i=n; i>=1; i--){
      if (checkcrucial(i)){
         return i;
      }
   }
   return -1;
}