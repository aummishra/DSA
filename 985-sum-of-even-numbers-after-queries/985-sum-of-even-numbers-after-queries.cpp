class Solution {
public:
    //O(n^2)
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        vector<int> ans;
        int sum  = 0;
          for(auto &it:nums){
                if(it%2 == 0) sum+= it;
            }
        int n =  q.size();
        for(int i=0;i<n;++i){
            int init = nums[q[i][1]];
            nums[q[i][1]] += q[i][0];
            int fin = nums[q[i][1]];
            if(init%2==0)
            sum-= init;
            if(fin%2 ==0)
            sum += fin;
            ans.push_back(sum);
        }
        return ans;
    }
};