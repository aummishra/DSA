class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            int temp = min(height[i],height[j]) * (j-i);
            ans = max(ans,temp);
            if(height[i]<height[j]){
                i++;
            }
            else if(height[j]<height[i]){
                j--;
            }
            else{
                i++;
                j--;
            }
        }
        return ans;
    }
};