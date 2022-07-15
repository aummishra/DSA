class Solution {
public:
    int help(vector<vector<int>>& grid,int row,int col){
        int n = grid.size();
       int m = grid[0].size();
        if((row<0 || row>=n) || (col<0 || col>=m)) return 0;
        if(grid[row][col]==0) return 0;
        grid[row][col] = 0;
        return 1 + help(grid,row+1,col) + help(grid,row-1,col) + help(grid,row,col+1) + help(grid,row,col-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans = max(ans,help(grid,i,j));
                }
            }
        }
        return ans;
    }
};