class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int,int>>> adj(points.size());
        int n = points.size();
        int cost = 0;
       // vector<int> dist(n+1,INT_MAX);
        vector<bool> vis(n,false);
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int d = abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }
       // vector<int> mst(1e6,false);
        //dist[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
         pq.push({0,0});
        while(!pq.empty()){
            pair<int,int> node = pq.top();
            pq.pop();
            if(vis[node.second]) continue;
            
                vis[node.second] = true;
                cost = cost + node.first;
            
           
            for(auto it:adj[node.second]){
                if(vis[it.first] == false ){
                    pq.push({it.second,it.first});
                    //dist[it.first] = it.second;
                }
            }
        }
        return cost;
    }
};