class Solution {
public:
    int dp[1005][1005];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int solve(vector<int>& nums, int target,int n){
       if(n==0 && target!=0){
           return 0;
       }
      if(target==0) return 1;
        if(dp[target][n]!=-1) return dp[target][n];
      if(nums[n-1]<=target){
          return dp[target][n]= solve(nums,target-nums[n-1],nums.size()) + solve(nums,target,n-1);
      }
        else
            return dp[target][n] = solve(nums,target,n-1);  
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums,target,n);
    }
};