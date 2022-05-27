class Solution {
public:
    int dp[202][1005];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int help(vector<int>& nums, int target,int n){
        if(n==0 && target!=0) return 0;
        if(target==0) return 1;
        if(dp[n][target]!=-1) return dp[n][target];
        if(nums[n-1]<=target){
            return dp[n][target] = help(nums,target-nums[n-1],nums.size()) + help(nums,target,n-1);
        }
        else {
            return dp[n][target] =  help(nums,target,n-1);
        }
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = help(nums,target,n);
        return ans;
    }
};