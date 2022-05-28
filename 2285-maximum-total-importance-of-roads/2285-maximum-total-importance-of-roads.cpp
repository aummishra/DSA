class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
       // int N = roads.size();
        vector<vector<int>> adj(n);
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> assign(n);
        int x = n;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<adj.size();i++){
            pq.push({adj[i].size(),i});
        }
        while(!pq.empty()){
            pair<int,int> a = pq.top();
            pq.pop();
            assign[a.second] = x;
            x--;
        }
        long long sum = 0;
        for(auto it:roads){
            long long temp = assign[it[0]] + assign[it[1]];
            sum+= temp;
           // cout<<temp<<" ";
        }
        return sum;
        
    }
};