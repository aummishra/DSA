class Solution {
public:
   int divide(int div, int d) {
        //double x = div/d;
       if(div==INT_MIN && d==-1) return INT_MAX;
        if(div>=0 && d>0 || div<0 && d<0){
            return div/d;
        }
           return -1*abs(div)/abs(d);
        
    }
};