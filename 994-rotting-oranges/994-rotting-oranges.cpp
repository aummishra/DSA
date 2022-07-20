class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2) {
                    q.push({i,j});
                    grid[i][j] = 0;
              }
            }
        }
        int cnt  = -1;
        while(!q.empty()){
            int N = q.size();
            for(int i=0;i<N;i++){
            auto temp = q.front();
            q.pop();
            if(temp.first < n-1 && grid[temp.first + 1][temp.second] == 1){
                q.push({temp.first+1,temp.second});
                grid[temp.first+1][temp.second] = 0;
            }
            if(temp.first >0 && grid[temp.first - 1][temp.second] == 1){
                q.push({temp.first-1,temp.second});
                grid[temp.first-1][temp.second] = 0;
            }
            if(temp.second < m-1 && grid[temp.first][temp.second + 1] == 1){
                q.push({temp.first,temp.second + 1});
                grid[temp.first][temp.second+1] = 0;
            }
            if(temp.second > 0 && grid[temp.first][temp.second - 1] == 1){
                q.push({temp.first,temp.second - 1});
                grid[temp.first][temp.second-1] = 0;
            }
            }
            cnt++;
        }
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1) {
                    return -1;
              }
            }
        }
        if(cnt == -1) return 0;
       /* if(grid.size()==1 && grid[0].size() == 1){
            if(grid[i][j]==0) return 0;
        }*/
       
        return cnt;
    }
};