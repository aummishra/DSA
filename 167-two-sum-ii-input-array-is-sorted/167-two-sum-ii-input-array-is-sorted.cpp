class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        int zc = 0;
       for(int i=0;i<numbers.size();i++){
           if(numbers[i]==0) zc++;
           if(numbers[i]==0 && zc == 2 && target ==0){
              ans.push_back(mp[0]);
               ans.push_back(i+1);
               break; 
           }
          /* if(numbers[i]==target){
                mp[numbers[i]] = i+1;
               continue;
           }*/
          int x = target - numbers[i];
           if(mp.find(x)!=mp.end()){
               ans.push_back(mp[x]);
               ans.push_back(i+1);
               break;
           }
           mp[numbers[i]] = i+1;
       }
        return ans;
    }
};