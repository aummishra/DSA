class Solution {
public:
    int count(vector<int>& bloomDay,int mid,int k){
        int cnt = 0;//7,7,7,7,12,7,7 , mid = 7,k = 3
        int x = 0;
        int ans = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid) {
                cnt++;
                x++;
            }
            else if(bloomDay[i]>mid){
                cnt = 0;
                x = 0;
            }
            if(x==k){
                ans++;
                cnt=0;
                x=0;
            }
         }
            return ans;
        }
        
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((bloomDay.size())/k < m) return -1;
        int lo=INT_MAX;
        int hi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            lo = min(lo,bloomDay[i]);
            hi = max(hi,bloomDay[i]);
        }
        long long mid;
        while(lo<hi){
            mid = (lo+hi)/2;
            if(count(bloomDay,mid,k)<m){
                lo = mid+1;
            }
            else 
                hi = mid;
        }
        return lo;
    }
};