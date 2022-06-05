class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n,0);
        int ans =0;
        for(int i=0;i<n;i++){
            for(auto it: words[i]){
                mask[i] = mask[i]| 1<<(it-'a'); // shifting 1 character times
            }
            for(int j=0;j<i;j++){ //Checking previous words to find words without any common character.
                if((mask[j] & mask[i])==0){
                    ans = max(ans,int(words[i].size()*words[j].size()));
                }
            }
        }
        return ans;
    }
};