class Solution {
public:
    int dp[51][51][51];
    int mod = 1e9+7;
    long long help(int m, int n, int maxMove, int row, int col){
        if((row>=m ||  row<0) || (col>=n || col<0)){
            return 1;
        }
        if(maxMove == 0) return 0;
        if(dp[maxMove][row][col]!=-1) return dp[maxMove][row][col];
        return dp[maxMove][row][col] = (help(m,n,maxMove-1,row+1,col)%mod + help(m,n,maxMove-1,row-1,col)%mod+ help(m,n,maxMove-1,row,col+1)%mod + help(m,n,maxMove-1,row,col-1)%mod)%mod;
    }
        
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return help(m,n,maxMove,startRow, startColumn);
    }
};