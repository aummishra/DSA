class Solution {
public:
    //TC : O(N + E), SC: N - color, N- queue, -> O(2N) -> O(N) , No adjacency list reqd worth SC: O(N+E) 
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
             queue<int> q;
             q.push(i);
             color[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it: graph[node])
                    {
                        if(color[it] == -1){
                            color[it] =  1 - color[node];
                           /* if(color[node]==1){
                                color[it]=0;
                            }
                            else{
                                color[it] = 1;
                            }*/
                            q.push(it);
                        }
                            else if(color[it]==color[node]){
                                return false;
                            }
                    }
                }
            }
        }
    return true;
    }
};//DFS Solution

/*class Solution {
public:
   bool dfs(int i, vector<int> &color,vector<vector<int>> &graph,int par){
    color[i] = 1-par;
     for(auto it: graph[i]){
         if(color[it]==-1){
             if(!dfs(it,color,graph,color[i])) return false;// if everycomponent of it doesnt return a false then the whole graph is bipartite and thus true
            // return dfs(it,color,graph,color[i]);
         }
         else if(color[it] == color[i]){
             return false;
         }
     }
    return true;
}

 bool isBipartite(vector<vector<int>>& graph){
 int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,color,graph,0)) return false;//if everycomponent of it doesnt return a false then the whole graph is bipartite and thus true therefore checking for !dfs because if we get a  true in any of its component and we return it but there is actually a component which is not bipartite then the whole graph will not be bipartite and we would declare it a bipartite based on our "if(dfs) -> return true" statement.
            }
        }
     return true;  //and after checking every component if it doesnt return any false then it means we can perform our bipartite operation on every vertex there fore our graph is bipartite
 }

};*/