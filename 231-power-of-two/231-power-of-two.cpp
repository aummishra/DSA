class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n>0)
            if(__builtin_popcount(n)==1 || n==1) return true;
    return false;
    }
};