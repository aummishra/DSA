class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<bitset<26>> bs(n);
        bool flag = false;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(auto it: words[i]){
                bs[i][it-'a'] = 1;
            }
            for(int j=0;j<i;j++){
                flag = false;
                for(int k=0;k<26;k++){
                    if(bs[i][k] && bs[j][k] == true){
                        flag = true;
                        break;
                    }
                }
                if(flag == false)
                ans = max(ans,int(words[i].size()*words[j].size()));
            }
        }
        return ans;
    }
};