class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> ans(n , vector<int> (n, 0)); 
        int m = 0,l = 0;
        int h = n-1,b= n-1;
        int j=0;
        while(m<=h && l<=b){
            for(int i=l;i<=b;i++){
                j++;
                ans[m][i] = j;
            }
            m++;
            for(int i=m;i<=h;i++){
                j++;
                ans[i][b] = j;
            }
            b--;
            if(m>h || l>b) break;
            for(int i=b;i>=l;i--){
                j++;
                ans[h][i] = j;
            }
            h--;
            for(int i=h;i>=m;i--){
                j++;
                ans[i][l] = j;
            }
            l++;
        }
        return ans;
    }
};