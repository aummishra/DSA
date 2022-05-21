class Solution {
public:
    vector<long long> sumOfThree(long long num) {
     unordered_map<long long,int> mp;
        int d = 3;
        vector<long long> ans;
        if(num%3==0){
            return {num/3 - 1,num/3,num/3 +1};
        }
        while(num!=0 && d!=0){
            long long t = num/d;
            num = num - t;
            if(mp.find(t)!=mp.end()) {
              return {};   
            }
            mp[t]++;
            ans.push_back(t);
            d--;
        }
        cout<<endl;
        return ans;
    }
};