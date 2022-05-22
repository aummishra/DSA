// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        map<long long,long long> mp;
        long long ans = 0;
        long long curr = 0;
        for(long long i=0;i<n;i++){
            curr += A[i];
            A[i]=curr;
            if(curr == 0){
                ans = max(ans,i+1);
            }
            else{
                if(mp.find(curr)!=mp.end()){
                    ans = max(ans,i-mp[curr]);
                }
                else{
                    mp[curr] = i;
                }
            }
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends