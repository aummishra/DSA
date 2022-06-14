class Solution {
public:
    //check notes
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 && j==0){
                    dp[i][j] = 0;
                }
                if(i==0 && j!=0) {
                    dp[i][j] = j;
                }
                if(i!=0 && j==0){
                    dp[i][j] = i;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] =  dp[i-1][j-1];
                }
                else{
                    int replace = dp[i-1][j-1];
                    int del  = dp[i-1][j];
                    int insert = dp[i][j-1];
                    dp[i][j] = 1 + min(replace,min(del,insert));
                }
            }
        }
        return dp[n][m];
        
    }
};