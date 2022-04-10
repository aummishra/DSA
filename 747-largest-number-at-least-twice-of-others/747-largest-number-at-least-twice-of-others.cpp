class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() ==1) return 0;
        int mx = INT_MIN;
        int idx = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mx){
                idx = i;
                mx = nums[i];
            }
        }
        nums[idx] = -1;
        int m = INT_MIN;
         for(int i=0;i<nums.size();i++){
            if(mx< 2*nums[i]){
                return -1;
            }
        }
        return idx;
    }
};