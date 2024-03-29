class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        map<char,int> mp;
        int i=0;
        int j=0;
        //int count=0;
        int n = s.length();
        while(j<n){
            mp[s[j]]++;
            //count = count + mp[s[j]]
            if(mp.size()==j-i+1){
                ans = max(ans,j-i+1);
                j++;
            }
            else if(mp.size()<j-i+1){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
                j++;
            }
        }
    return ans;
    }
};