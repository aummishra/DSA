class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int,int>> freq(26,{0,0});
        int mx = INT_MAX;
        for(int i=0;i<s.length();i++){
            if(freq[s[i]-'a'].second==0){
              freq[s[i]-'a'] = {i,1};  
            }
            else{
                freq[s[i]-'a'].second++;
            }
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i].second == 1){
                mx = min(mx,freq[i].first);
            }
        }
        if(mx==INT_MAX) return -1;
        return mx;
    }
};