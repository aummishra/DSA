class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=1;i<n-1;i++){
            int c = nums[i+1];
            int a = nums[i-1];
            int b = nums[i];
            if(c>=a){
                if(b>c) {
                    nums[i] = nums[i+1];
                    cnt++;
                }
                if(a>b){
                    nums[i-1] = nums[i];
                    cnt++;
                }
            }
            else if(c<a){
                if(a>b){
                    nums[i-1] = nums[i];
                    cnt++;
                }
                 if(c<b){
                    nums[i+1] = nums[i];
                    cnt++;
                }
            }
        }
        if(cnt>1) return false;
        return true;
    }
};