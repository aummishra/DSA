class Solution {
public:
    int dp[51][51][51];
    int mod = 1e9+7;
    long long help(int m, int n, int maxMove, int row, int col, vector<vector<int>> &grid){
        if((row>=m ||  row<0) || (col>=n || col<0)){
            return 1;
        }
        if(maxMove == 0) return 0;
        if(dp[maxMove][row][col]!=-1) return dp[maxMove][row][col];
        return dp[maxMove][row][col] = (help(m,n,maxMove-1,row+1,col,grid)%mod + help(m,n,maxMove-1,row-1,col,grid)%mod+ help(m,n,maxMove-1,row,col+1,grid)%mod + help(m,n,maxMove-1,row,col-1,grid)%mod)%mod;
    }
        
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        memset(dp,-1,sizeof(dp));
        return help(m,n,maxMove,startRow, startColumn,grid);
    }
};