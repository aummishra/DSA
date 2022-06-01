class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int ans = nums[0];
        vector<int> res;
        res.push_back(ans);
        for(int i=1;i<nums.size();i++){
            ans+= nums[i];
            res.push_back(ans);
        }
        return res;
    }
};