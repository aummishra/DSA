class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zc = 0;
        int oc = 0;
        int tc = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zc++;
            else if(nums[i]==1) oc++;
            else if(nums[i]==2) tc++;
        }
        for(int i=0;i<zc;i++){
            nums[i] = 0;
        }
        for(int i=zc;i<oc+zc;i++){
            nums[i] = 1;
        }
        for(int i=oc+zc;i<tc+zc+oc;i++){
            nums[i] = 2;
        }
    }
};