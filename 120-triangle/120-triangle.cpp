class Solution {
public:
    //Memoization to store minimum path from a particular row and col.
   // int dp[201][201];
    // cant store it in a 1d vector (memoize the minimum path from each row) as some columns of the below row would not be possible from the previous row. 
    /*Solution(){
        memset(dp,-1,sizeof(dp));
    }*/
   /* int solve(vector<vector<int>>& triangle,int row,int col){
        int n = triangle.size();
        if(row == n-1){
            return triangle[row][col];
        }
        if(row>=n || col>= triangle[row].size()){
            return 0;
        }
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col] = triangle[row][col] + min(solve(triangle,row+1,col),solve(triangle,row+1,col+1));
        
    }*/
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dp[n][n];
        for(int j=0;j<=n-1;j++){
            dp[n-1][j] = triangle[n-1][j]; 
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,diagonal);
            }
        }
       int ans = dp[0][0];
       // int ans = solve(triangle,0,0);
        return ans;
    }
        //Top down - 
        
        
};
/*int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<int>next(n);
		for(int i = n-1; i >= 0; i--) {
			vector<int>curr(n);
			for(int j = i; j >= 0; j--) {
				if(i == n-1)
					curr[j] = triangle[i][j];
				else {
					int up = triangle[i][j] + next[j];
					int up_left = triangle[i][j] + next[j+1];
					curr[j] = min(up, up_left);
				}
			}
			next = curr;
		}
		return next[0];
	}*/