class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //sliding window
        map<int,int> mp;
        int ans = INT_MIN;
        int sum = 0;
        int j= 0;
        int i =0;
        bool flag = true;
        while(j<nums.size()){
            if(flag){
              mp[nums[j]]++;
            sum += nums[j];  
            }
            if(mp.size()==j-i+1){
                ans = max(sum,ans);
                j++;
                flag = true;
            }
            else if(mp.size()<j-i+1){
               flag = false;
                mp[nums[i]]--;
                sum = sum - nums[i];
                //ans = max(sum,ans);
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};