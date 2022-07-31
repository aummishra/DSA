class Solution {
public:
    void dfs(vector<vector<int>> &adj,int &node,vector<int> &nodes, vector<int> &vis, int dist){
        vis[node] = 1;
        nodes[node] = dist;
        
        for(auto &it: adj[node]){
            if(it == -1) break;
            if(!vis[it]){
                vis[it] = 1;
                dist++;
                dfs(adj,it,nodes,vis,dist);
            }
        }
        
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> adj(n); 
        vector<int> vis(n,0);
        int idx = -1;
        int dist  = 0;
        int ans = n+2;
        for(int i=0;i<n;++i){ //O(N)
            adj[i].push_back(edges[i]);
        }
        vector<int> n1(n,-1);
        vector<int> n2(n,-1);
        dfs(adj,node1,n1,vis,0);//O(N)
        vector<int> visi(n,0);
         //vis.resize(n,0);    
        dfs(adj,node2,n2,visi,0);//O(N)
        for(int i=0;i<n;++i){
            if(n1[i]!=-1 && n2[i]!=-1){
                dist = max(n1[i],n2[i]);
                if(dist<ans){
                    ans = dist;
                    idx = i;
                }
            }
        }
        return idx;
    }
};