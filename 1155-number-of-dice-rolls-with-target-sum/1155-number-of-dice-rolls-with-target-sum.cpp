class Solution {
public:
    int mod = 1e9+7;
    int dp[31][1001];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int numRollsToTarget(int n, int k, int t) {
        if(t==0 && n==0) return 1;
        if(n<=0) return 0;
        if(dp[n][t]!=-1) return dp[n][t];
        int out = 0;
        for(int i=1;i<=k;i++){
            if(i<=t){
                out = (out +  numRollsToTarget(n-1,k,t-i))%mod;
            }
        }
        return dp[n][t] = out;
    }
};