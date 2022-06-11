class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        int req = 0;
        for(auto it: nums){
            sum += it;
        }
        req = sum - x;
        int res = INT_MIN;
        int i = 0;
       // int j= 0;
        int curr = 0;
        for(int j=0;j<nums.size();j++){
            curr += nums[j];
            while(i<=j && curr>req){
                curr = curr-nums[i];
                i++;
            }
            if(req == curr) res = max(res,j-i+1);
        }
        if(res == INT_MIN) return -1;
        return nums.size()-res;
    }
};