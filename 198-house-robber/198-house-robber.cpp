class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums,int i){
        if(i==nums.size()-1){
            return nums[i];
        }
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(nums[i] + solve(nums,i+2), solve(nums,i+1));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1,-1);
       return solve(nums,0); 
    }
};