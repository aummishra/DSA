class Solution {
public:
    int numRescueBoats(vector<int>& pp, int limit) {
        sort(pp.begin(),pp.end());
        int cnt = 0;
        int i= 0;
        int j= pp.size()-1;
        int curr = limit;
        while(i<=j){
          if(pp[i] + pp[j] <=curr){
              i++;
              j--;
          }
        else {
          j--;
        }
            cnt++;
        }
        return cnt;
    }
};