class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& cost,int i,int n){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int o1=0,o2=0;
        o1 += cost[i] + solve(cost,i+1,n);
        o2 += cost[i] + solve(cost,i+2,n);
         
        return dp[i] = min(o1,o2);
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n,-1);
        int ans1 = solve(cost,0,n);
        int ans2 = solve(cost,1,n);
        return min(ans1,ans2);
    }
};