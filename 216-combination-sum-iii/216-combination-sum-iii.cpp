class Solution {
public:
    set<int> st;
    set<vector<int>> st1;
    void helper(int k,int n,vector<vector<int>> &ans,vector<int> &temp,int start){
        if(n==0 && k==0){
        //    sort(temp.begin(),temp.end());
          //  if(st1.find(temp)!=st1.end()) return;
            ans.push_back(temp);
           // st1.insert(temp);
            return;
        }
        //if(n<0) return;
        for(int i=start;i<=9;i++){
            temp.push_back(i);
            helper(k-1,n-i,ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k>n) return {};
       vector<vector<int>> ans;
        vector<int> temp;
        int start = 1;
         helper(k,n,ans,temp,start);
       // st1.clear;
        return ans;
    }
};