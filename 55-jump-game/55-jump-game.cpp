class Solution {
public:
    vector<int> dp;
   bool solve(vector<int>& nums,int i,int n){
       if(i==n){
           return true;
       }
       if(i>n){
           return false;
       }
       if(dp[i]!=-1) return dp[i];
       bool ans = false;
      // if(nums[i]==0) return false;
       for(int j=1;j<=nums[i];++j){
           if(ans==true) return dp[i]=true;
           ans = (ans || solve(nums,i+j,n));
       }
       return dp[i] = ans;
   }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
     return solve(nums,0,n-1);   
    }
};