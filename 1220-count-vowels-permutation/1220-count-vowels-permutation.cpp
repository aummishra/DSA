class Solution {
public:
    int dp[20005][27];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int mod = 1e9+7;
    int solve(int n,char c){
        if(n<=0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(dp[n][c-'a']!=-1) return dp[n][c-'a']%mod;
        if(c == 'a'){
           return dp[n][c-'a'] = solve(n-1,'e')%mod;
        }
        else if(c=='e'){
            return dp[n][c-'a'] = (solve(n-1,'a')%mod + solve(n-1,'i')%mod)%mod;
        }
        else if(c=='i'){
            return dp[n][c-'a'] = ((solve(n-1,'a')%mod + solve(n-1,'e')%mod)%mod + (solve(n-1,'o')%mod + solve(n-1,'u')%mod)%mod)%mod;
        }
        else if(c=='o'){
            return dp[n][c-'a'] = (solve(n-1,'i')%mod + solve(n-1,'u')%mod)%mod;
        }
        return dp[n][c-'a'] = solve(n-1,'a')%mod;
    }
    int countVowelPermutation(int n) {
        vector<char> ch = {'a','e','i','o','u'};
        int ans = 0;
        for(int i=0;i<ch.size();i++){
            ans = ans + solve(n,ch[i]);
            ans = ans%mod;
        }
        return ans;
    }
};