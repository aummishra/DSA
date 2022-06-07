class Solution {
public:
    int dp[201][201];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int solve(vector<vector<int>>& grid,int row,int col){
        int m = grid.size()-1;
        int n = grid[0].size()-1;
        if(row>m || col>n){
            return INT_MAX;
        }
        if(row==m && col==n){
            return grid[m][n];
        }
        if(dp[row][col]!=-1) return dp[row][col];
        int down = solve(grid,row+1,col);
        int right = solve(grid,row,col+1);
        return dp[row][col]=grid[row][col]+min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        return solve(grid,0,0);
    }
};