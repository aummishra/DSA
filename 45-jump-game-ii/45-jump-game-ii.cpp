class Solution {
public:
    vector<int> dp;
   int solve(vector<int> &nums,int i,int n){
  if(i==n){
  	return 0;
  }
  if(i>n) return INT_MAX-1;
       if(dp[i]!=-1) return dp[i];
  int ans = INT_MAX-1;
  for(int j=1;j<=nums[i];j++){
  	ans =  min(ans,1 + solve(nums,i+j,n));
  }
  return dp[i] = ans;
}
    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        return solve(nums,0,n-1);
    }
};