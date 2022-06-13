class Solution {
public:
    //Memoization to store minimum path from a particular row and col.
    int dp[201][201];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int solve(vector<vector<int>>& triangle,int row,int col){
        int n = triangle.size();
        if(row == n-1){
            return triangle[row][col];
        }
        if(row>=n || col>= triangle[row].size()){
            return 0;
        }
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col] = triangle[row][col] + min(solve(triangle,row+1,col),solve(triangle,row+1,col+1));
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = solve(triangle,0,0);
        return ans;
    }
};