class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        int numRows = rowIndex;
        ans.push_back({1});
        if(numRows == 0) return {1};
        for(int i=2;i<=34;i++){
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
          for(int i=0;i<ans.size();i++){
              if(i==rowIndex) return ans[i];
          }
        
            //return res;
        return {0};
    }
};