class Solution {
public:
    int fib(int n) {
       int f = 0;
        int s = 1;
        int t=0; 
        if(n==0 || n==1) return n;
        for(int i=1;i<n;i++){
         t = f+s;
            f= s;
            s= t;
        }
        return t;
    }
};