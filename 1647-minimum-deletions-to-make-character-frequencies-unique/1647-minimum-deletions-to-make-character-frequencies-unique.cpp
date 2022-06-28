class Solution {
public:
    int minDeletions(string s) {
        vector<char> v(1e5+1,'0');
        map<char,int> mp;
        int ans = 0;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it:mp){
            if(v[it.second] == '0')
            v[it.second] = it.first;
            else if( v[it.second] != '0' ){
                while(it.second >0 && v[it.second] !='0'){
                 it.second -= 1;
                ans++;
                //if(it.second < 0)continue;
                 //
                }
                if(it.second >=0) v[it.second] = it.first;
            }
        }
        return ans;
    }
};