/*class Solution {
public:
    int timer=0;
    void dfs(int i,vector<vector<int>> &ans,vector<vector<int>> adj,vector<int> &low,vector<int> &in,vector<int> &vis,int parent){
        vis[i] =1;
        low[i] = in[i] = timer;
        timer++;
        for(auto &it:adj[i]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,ans,adj,low,in,vis,i);
                low[i] = min(low[it],low[i]);
                if(low[it]>low[i]){
                    ans.push_back({i,it});
                }   
            }
            else {
                low[i] = min(low[i],in[it]);
            }  
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> low(n,-1);
        vector<int> in(n,-1);
        timer =0;
        int parent = -1;
        for(int i=0;i<n;i++){
            if(!vis[i])
               dfs(i,ans,adj,low,in,vis,parent);
        }
       // ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }  
};*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> graph;
    vector<int> id;
    vector<int> lowlink;
    vector<bool> vis;
    int time=0;
    void dfs(int node,int parent)
    {
        id[node]=lowlink[node]=time++;
        vis[node]=true;
        for(int &x:graph[node])
        {
            if(parent==x)continue;
            if(vis[x]==false)
            {
                dfs(x,node);
                lowlink[node]=min(lowlink[node],lowlink[x]);
                if(id[node]<lowlink[x])
                    ans.push_back({node,x});
            }
            else 
                lowlink[node]=min(lowlink[node],id[x]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        vis.resize(n,false);
        lowlink.resize(n,0);
        id.resize(n,0);
        for(auto &x:connections)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
                dfs(i,i);
        }
        return ans;
    }
};