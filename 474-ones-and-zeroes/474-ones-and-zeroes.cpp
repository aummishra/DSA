class Solution {
public:
     vector<array<int,2>>v;
    int m,n,sz;
    int dp[601][101][101];
    
    int f(int idx, int z, int o ){
        if(idx>=sz)return 0;
        if(dp[idx][z][o]!=-1)return dp[idx][z][o];
        int op1=0,op2=0;
        if(z+v[idx][0]<=m && o+v[idx][1]<=n){
            op1=1+f(idx+1,z+v[idx][0],o+v[idx][1]);
        }
        op2=f(idx+1,z,o);
        return dp[idx][z][o]=max(op1,op2);
    }
    int findMaxForm(vector<string>& s, int m, int n) {
         v.resize(s.size());
        this->sz=v.size();
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s[i].size();j++){
               v[i][s[i][j]-'0']++;        
            }
        }
        this->m=m;this->n=n;
        memset(dp,-1,sizeof dp);
        return f(0,0,0);
    }
};
