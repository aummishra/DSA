class Solution {
public:
     vector<int> dp;
    //set<int> idx;
    int solve(vector<int>& nums,int i){
        if(i==nums.size()-1){
            return nums[i];
        }
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(nums[i] + solve(nums,i+2), solve(nums,i+1));
    }
    int rob(vector<int>& nums) {
        vector<int> v1(nums.begin(),nums.end()-1);
        vector<int> v2(nums.begin() + 1,nums.end());
        int n = nums.size();
        if(n==1) return nums[0];
        dp.resize(n,-1);
        //if(v1.size()==1 && v2.size()==1) return max(v1[0],v2[0]);
        int ans1 = solve(v1,0);
        //cout<<ans1<<" ";
        dp.clear();
        dp.resize(n,-1);
        int ans2 = solve(v2,0);
       // cout<<ans2;
       return max(ans1,ans2); 
    }
};