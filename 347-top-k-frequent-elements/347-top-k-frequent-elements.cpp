class Solution {
public:
   static bool MYcomparator(pair<int,int> a , pair<int,int> b){
       return b.second < a.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> x;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            x.push_back(make_pair(it.first,it.second));
        }
        sort(x.begin(),x.end(),MYcomparator);
        vector<int> v;
      for(auto i=x.begin();i!=x.begin()+k;i++){
          v.push_back(i->first);
      }
  return v;
        }
};