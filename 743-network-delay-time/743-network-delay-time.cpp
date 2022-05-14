class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //adj list
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                   // dist[it.first] = min(dist[it.first], it.second + dist[node]);
                //if we use the above condition then the if loop will also run for the cases when the new distance will be qual to previos distance thus it will result in TLE. therefore, we only check if our new dist is smaller than previous thus,  faster TC.
                if(dist[it.first] > it.second + dist[node]){
                    dist[it.first] =  it.second + dist[node];
                    pq.push({dist[it.first],it.first});
                }    
            }
        }
        int ans = -1;
        for(int i=1;i<=n;i++){
            if(dist[i] ==  INT_MAX){
            ans = -1;
                break;
            }
            else{
                ans = max(ans,dist[i]);
            }
        }
        return ans;
    }
};