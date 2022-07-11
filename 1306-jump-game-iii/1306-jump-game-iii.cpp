class Solution {
public:
    vector<int> vis;
    bool solve(vector<int>& arr, int start){
         int n = arr.size();
        if(start>=n || start<0) return false;
        if(arr[start] == 0) return true;
        bool o1 = false,o2=false;
        if(vis[start]==0){
            vis[start] = 1;
             o1 = solve(arr,start+arr[start]);
             o2 = solve(arr,start-arr[start]);
        }
        
        return  o1||o2;
    }
    bool canReach(vector<int>& arr, int start) {
      int n = arr.size();
        vis.resize(n,0);
        return solve(arr,start);
    }
};