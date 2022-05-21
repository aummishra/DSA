class Solution {
public: //Top Down Approach
    int dp[13][10002];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int sol(vector<int>& coins,int n, int amt){
         if(amt == 0){
            return 0;
        }
        if(n==0){
            return INT_MAX - 1;
        }
        if(dp[n][amt]!=-1){
            return dp[n][amt];
        }
        if(coins[n-1]<=amt){
            return dp[n][amt] = min(1+sol(coins,n,amt-coins[n-1]),sol(coins,n-1,amt));
        }
        else{
            return dp[n][amt] = sol(coins,n-1,amt);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
       int ans = sol(coins,n,amount);
        if(ans == INT_MAX - 1){
            return -1;
        }
        return ans;
    }
};