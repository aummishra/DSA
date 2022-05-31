class Solution {
public:
    int help(vector<int>& nums,int mid){
        int val = 0;
        for(int i=0;i<nums.size();i++){
           if(nums[i]%mid==0){
               val+= nums[i]/mid;
           }
            else{
                val+= nums[i]/mid + 1; 
            }
        }
        return val;
    }
    
    int smallestDivisor(vector<int>& nums, int th) {
        int lo = 1;
        int hi;
        for(int i=0;i<nums.size();i++){
            hi = max(hi,nums[i]);
        }
        long long mid;
        while(lo<hi){
            mid = (lo+hi)/2;
            if(help(nums,mid)>th){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        return lo;
       //Brute force solution - TLE, TC - O(N*10^6) as nums[i] can be upto 10^6, N can be upto 5*10^4.
      /*  int ans=0;
        for(int j=1;j<=hi;j++){
            ans = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]%j==0) ans+= nums[i]/j;
                else ans+= nums[i]/j +1;
            }
            if(ans<=th){
               // cout<<j<<" ";
                return j;
            }
        }
        return 0;*/
    }
};