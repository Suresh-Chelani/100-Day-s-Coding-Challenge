#include <iostream>

using namespace std;

class Solution {
  public:
    int countNumberswith4(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            int num=i;
            while(num>0){
                if(num%10==4){
                    cnt++;
                    break;
                }
                num=num/10;
            }
        }
        return cnt;
    }
};

/*

class Solution {
  public:
    int countNumberswith4(int n) {
        int c = 0;
        
        for (int i=1; i<=n; i++){
            string s = to_string(i);
            for (char ch: s){
                if (ch == '4'){
                    c+=1;
                    break;
                }
            }
        }
        return c;
    }
};
*/