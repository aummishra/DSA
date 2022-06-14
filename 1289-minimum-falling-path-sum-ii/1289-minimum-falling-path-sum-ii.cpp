class Solution {
public:
    int dp[201][201];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int solve(vector<vector<int>>& matrix,int row,int col){
        int n = matrix.size();
        if(col<0 || col>=n) return INT_MAX;
        if(row == n-1) return matrix[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        //int out = 0;
        int temp = INT_MAX;
        for(int i=0;i<n;i++){
            if(i==col) continue;
              temp = min(temp,solve(matrix,row+1,i));
        }
        return dp[row][col] = matrix[row][col] + temp;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int n= grid.size();
        for(int i=0;i<n;i++){
            ans = min(ans,solve(grid,0,i));
        }
        return ans;
    }
};