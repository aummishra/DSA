class Solution {
public:
   void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size()-1;
        int n = matrix[0].size()-1;
        vector< vector<int>> ans;
        for(int j=0;j<=n;j++){
            vector<int> temp;
            for(int i=m;i>=0;i--){
               temp.push_back(matrix[i][j]);
            }
        ans.push_back(temp);
        }
        matrix = ans;
    }
};