// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
long long mod = 1e9+7;
	public:
	int help(int arr[], int n){
	    int cnt =0;
	    for(int i=0;i<=n;i++){
	        if(arr[i]==0) cnt++;
	    }
	    return cnt;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0) dp[i][j] = 0;
                if(j==0) dp[i][j] = pow(2,help(arr,i));
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j){
                    dp[i][j] = (dp[i-1][j-arr[i-1]]%mod + dp[i-1][j]%mod)%mod;
                }
                else {
                    dp[i][j] = dp[i-1][j]%mod;
                }
            }
        }
        return dp[n][sum];
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends