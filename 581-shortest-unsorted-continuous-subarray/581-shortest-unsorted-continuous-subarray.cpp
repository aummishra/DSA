class Solution {
public:
    //O(N)logN solution
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(),v.end());
        int st = 0;
        int end = 0;
        if(v==nums) return 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=v[i]){
                st = i;
                break;
            }
        }
        for(int j=nums.size()-1;j>=0;j--){
            if(nums[j]!=v[j]){
                end = j;
                break;
            }
        }
        return end-st+1;
    }
};