 map<char,int> mp;
bool myComp(char a, char b){
    if(mp[a]==mp[b]) return a>b;
        return mp[a]>mp[b];
    }
class Solution {
public:
   
     
    string frequencySort(string s) {
        for(int i=0;i<s.length();i++){
          
            mp[s[i]]++;
        }
       // cout<<mp['A']<<" "<<mp['b'];
        sort(s.begin(),s.end(),myComp);
        mp.clear();
        return s;
    }
};