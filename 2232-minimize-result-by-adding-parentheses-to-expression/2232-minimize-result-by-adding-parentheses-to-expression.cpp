class Solution {
public:
    string minimizeResult(string s) {
        int idx = -1;
        string res ="";
        int ans = INT_MAX;
        for(int i=0;i<s.length();i++){
            if(s[i]=='+') {
                idx = i;
                 break;
            }
        }
        for(int i=0;i<idx;i++){
            for(int j=idx+1;j<s.length();j++){
                string a = s.substr(0,i);
                string b = s.substr(i,idx-i);
                string c = s.substr(idx+1,j-idx);
                string d = s.substr(j+1);
                int p,q,r,s;
                if(a=="") p = 1;
                else if(a!="") p = stoi(a);
                if(b=="") q = 1;
                else if(b!="") q = stoi(b);
                if(c=="") r = 1;
                else if(c!="") r = stoi(c);
                if(d=="") s = 1;
                else if(d!="") s = stoi(d);
                
                int temp =  p*(q+r)*s;
                if(temp<ans){
                    ans = temp;
                    res = a + "(" + b + "+" + c + ")" + d;
                }
                
            }
            
        }
        return res;
        
        
    }     
};