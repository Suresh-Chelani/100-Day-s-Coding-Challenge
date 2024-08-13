class Solution {
  public:
    typedef long long int ll;
    ll floorSqrt(long long int n) {
        ll s = 1;
        ll e = n;
        ll ans = 0;
        while (s <= e){
            ll mid = s + (e - s)/2;
            ll isperfect = mid*mid;
            if (isperfect == n){
                return mid;
            }
            else if (isperfect > n){
                e = mid - 1;
            }
            else{
                ans = mid;
                s = mid + 1;
            }
        }
        
        return ans;
    }
};
