class Solution {
public:
    int dp[101][101];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int solve(vector<vector<int>>& matrix,int row,int col){
        int n = matrix.size();
        if(col<0 || col>=n) return INT_MAX;
        if(row == n-1) return matrix[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int left = solve(matrix,row+1,col-1);
        int down = solve(matrix,row+1,col);
        int right = solve(matrix,row+1,col+1);
        
        return dp[row][col] = matrix[row][col] + min(down,min(left,right));
        
    }
       
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        for(int i=0;i<matrix[0].size();i++){
            ans = min(ans , solve(matrix,0,i));
        }
        return ans;
    }
};