class Solution {
public:
    void gameOfLife(vector<vector<int>>& b) {
        vector<vector<int>> ans =  b;
        int m = b.size();
        int n = b[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cnt  = 0;
                if(i-1>=0) cnt += b[i-1][j];
                if(j-1>=0) cnt += b[i][j-1];
                if(j+1<n) cnt+= b[i][j+1];
                if(i+1<m) cnt+= b[i+1][j];
                if(i+1<m && j+1<n) cnt+= b[i+1][j+1];
                if(i+1<m && j-1>=0) cnt+= b[i+1][j-1];
                if(i-1>=0 && j+1<n) cnt += b[i-1][j+1];
                if(i-1>=0 && j-1>=0) cnt += b[i-1][j-1];
                
                if(b[i][j]==1){
                    if(cnt<2 || cnt>3){
                        ans[i][j]=0;
                    }
                    else if(cnt ==2 || cnt==3){
                        ans[i][j] = 1;
                    }
                }
                else{
                    if(cnt==3) ans[i][j]=1;
                }
            }
        }
        b = ans;
    }
};