class Solution {
public:
    int help( vector<int>& quantities,int mid){
        int cnt = 0;
        for(auto it:quantities){
            cnt += it/mid + 1;
            if(it%mid==0) cnt--;
        }
        return cnt;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo,hi;
        for(auto it: quantities){
            hi = max(hi,it);
        }
        lo = 1;
        long long mid;
        while(lo<hi){
            mid = (lo+hi)/2;
            if(help(quantities,mid)>n){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        return lo;
    }
};