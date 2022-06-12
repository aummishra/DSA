class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int> st;
        int ans = INT_MIN;
        int sum = 0;
        int j= 0;
        int i =0;
      while(j<nums.size()){
         while(st.find(nums[j])!=st.end()){
              sum = sum -nums[i];
             st.erase(nums[i]);
             i++;
          }
          st.insert(nums[j]);
          sum += nums[j];
          ans = max(ans,sum);
          j++;
      }
        return ans;
    }
};