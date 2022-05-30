class Solution {
public:
    int help(vector<int> nums,int mid){
        int cnt  =0;
        for(int i=0;i<nums.size();i++){
           cnt += nums[i]/mid;
            if(nums[i]%mid==0) cnt--;
        }
        return cnt;
    }
    int minimumSize(vector<int>& nums, int op) {
        int lo=1,hi=0;
        long long mid;
        //int sum =0;
        for(int i=0;i<nums.size();i++){
           // hi += nums[i]-1;
            hi = max(hi,nums[i]);
        }
        //hi = sum;
        //lo = 1;
        while(lo<hi){
            mid = (lo + hi)/2;
            mid = (lo + hi)/2;
            if(help(nums,mid)<=op){
                hi = mid;
            }
            else
                lo = mid+1;
        }
        return hi;
    }
};