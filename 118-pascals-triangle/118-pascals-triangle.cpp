class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows == 1) return ans;
        for(int i=2;i<=numRows;i++){
            vector<int> temp;
            for(int j=0;j<i;j++){
                if(j==0 || j==i-1){
                    temp.push_back(1);
                }
                else
                temp.push_back(ans[i-2][j-1] + ans[i-2][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};