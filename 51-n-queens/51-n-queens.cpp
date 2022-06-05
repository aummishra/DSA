class Solution {
public:
    bool safe(int i,int col,vector<string> &v, int n){
        int x=i;
        int y = col;
        while(x>=0 && y>=0){
            if(v[x][y]=='Q') return false;
            x--;
            y--;
        }
        x = i;
        y = col;
        while(y>=0){
            if(v[x][y]=='Q') return false;
            y--;
        }
        y = col;
        while(x<n && y>=0){
            if(v[x][y] == 'Q') return false;
            x++;
            y--;
        }
        return true;
        
    }
    void help(int n, vector<vector<string>> &ans,vector<string> &v, int col){
        if(col==n) {
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(safe(i,col,v,n)){
                v[i][col] = 'Q';
                help(n,ans,v,col+1);
                v[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
        vector<string> v(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            v[i] = s;
        }
        help(n,ans,v,0);
        return ans;
    }
};