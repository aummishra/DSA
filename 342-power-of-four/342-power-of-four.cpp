class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1) return false;
        int ones = __builtin_popcount(n);
        int x = (int)log2(n)+1;
        if(ones == 1 && x%2!=0) return true;
        return false;
    }
};