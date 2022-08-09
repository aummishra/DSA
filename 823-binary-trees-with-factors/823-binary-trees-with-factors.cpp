class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& a) {
        sort(a.begin(),a.end());
        int mod = pow(10,9)+ 7;
        map<int,long long> mp;
        for(auto it:a){
            mp[it]++;
        }
        for(int i=0;i<a.size();i++){
            long long temp = 1;
            for(auto it:mp){
                if(a[i]%it.first == 0 && mp.find(a[i]/it.first) !=mp.end())
                temp += mp[(a[i]/it.first)]*it.second;
                //temp = temp%mod;
            }
            mp[a[i]] = temp; 
        }
        int ans  = 0;
        for(auto it:mp){
            ans  = (ans + it.second)%mod;
        }
        return ans;
    }
};