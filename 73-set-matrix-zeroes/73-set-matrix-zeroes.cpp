class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int,int> row;
        map<int,int> col;
       // bool flag = false;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        for(int i=0;i<matrix.size();i++){
             //flag = true;
            for(int j=0;j<matrix[i].size();j++){
                if(col.find(j)!=col.end()) {
                    matrix[i][j]=0;
                }
               if(row.find(i)!=row.end()){
                   matrix[i][j]=0;
               }
            }
        }
    
    }
};