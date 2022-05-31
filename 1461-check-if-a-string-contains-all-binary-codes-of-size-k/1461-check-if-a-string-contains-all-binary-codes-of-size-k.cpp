class Solution {
public:
    //Approach - Every binary code of length k means, if k =2 then 00,01,10,11 - [0,1,2,3] should be present.
    //That is if k = 2 then total binary codes = pow(2,2) [and highest possible integer code = pow(2,2)-1]
    // if k = 3 then code possible till 7[111] (as 8 is 1000) so total codes possible = pow(2,3)[0-7] and
    // Last integer = 2^3-1;
    // if k =4 then last integer 15[1111]i.e, 2^4-1 and total codes = 2^4.
    //so if our k value is 2, then we create a window of size 2 and traverse our input string s and mark all the 
    // binary value of our window as true in an array. then we iterate the array from 0 to 2^k-1 and find if all the
    // values are marked or not, if not then we'll return false otherwise return true.
    
    // now how we will convert our binary to integer after each slide.
    // if our window s = 001101 and k =2 
    // so for i=0,[0] val = val*2 + s[i] * pow(2,s[i]) = 0*2 + 0 * 2^0   = 0
    // for i=1,[00] val += val*2 + s[i]pow(2,s[i]), val = 0 +  0*2 + 0*2^0 = 0
    // i=2,[001] val  += val*2 + s[i]pow(2,0), val = 0 + 0*2 + 1*1 = 1
    // i= 3,[0011] val += val*2 + s[i]pow(2,0), val = 1 + 1*2 + 
   // 1101 , n= 4 , k =3
    
    int help(string s){
        int val = 0;
        for(int i=0;i<s.length();i++){
            val = val*2 + s[i]-'0';
        }
        return val;
    }
    bool hasAllCodes(string s, int k) {
         int i = 0;
        int j = k;
        int n = pow(2,k);
        if(k>s.length()) return false;
        vector<int> v(n,-1);
        while(i<s.length()-k+1){
            string t = s.substr(i,k);
            int x = help(t);
            v[x] = 0;
            i++;
        }
        for(int i=0;i<n;i++){
            if(v[i]==-1) return false;
        }
        return true;
    }
};