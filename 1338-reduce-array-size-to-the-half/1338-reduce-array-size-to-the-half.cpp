class Solution {
public:
    static bool myComp(pair<int,int> a, pair<int,int> b){
        return a.second> b.second;
    }
    int minSetSize(vector<int>& arr) {
       vector<pair<int,int>> v;
        unordered_map<int,int> mp;
        for(auto it: arr){
            mp[it]++;
        }
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),myComp);
        int n = arr.size();
        int N = n;
        int i = 0;
        int st = 0;
        while(i<N && N>(n/2)){
            N = N - v[i].second;
            i++;
            st++;
        }
        return st;
    }
};