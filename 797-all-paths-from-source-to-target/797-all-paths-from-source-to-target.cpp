class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<vector<int>> &ans, int node,vector<int> &vis,vector<int> temp){
        temp.push_back(node);
        //vis[node] = 1;
        for(auto it:adj[node]){
           // temp.push_back(it);    
            //if(vis[it]!=0){
                dfs(adj,ans,it,vis,temp);
            //}
           // vis[node] = 0;
        }
        if(node == adj.size()-1){
            ans.push_back(temp);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<vector<int>> ans;
        vector<int> vis(n,0);
        vector<int> temp;
       // temp.push_back(0);
       dfs(adj,ans,0,vis,temp);
        return ans;
    }
};