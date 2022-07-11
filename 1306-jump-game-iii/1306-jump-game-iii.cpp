class Solution {
public:
    //vector<int> dp;
    vector<int> vis;
    bool solve(vector<int>& arr, int start){
         int n = arr.size();
        if(start>=n || start<0) return false;
        if(arr[start] == 0) return true;
       // if(dp[start]!=-1) return dp[start];
        bool o1 = false,o2=false;
        if(vis[start]==1) return false;
        if(vis[start]==0){
            vis[start] = 1;
             o1 = solve(arr,start+arr[start]);
             o2 = solve(arr,start-arr[start]);
        }
        
        return  (o1||o2);
    }
    bool canReach(vector<int>& arr, int start) {
      int n = arr.size();
         // vector<int> vis;
        vis.resize(n,0);
        //dp.resize(n,-1);
        return solve(arr,start);
    }
};