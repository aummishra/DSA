class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1) return true;
        int ones = __builtin_popcount(n);
        if(ones==1){
            int cnt  = 0;
            while(n>1){
                n = n>>1;
                cnt++;
            }
            if(cnt && cnt%2==0) return true;
        }
        return false;
    }
};