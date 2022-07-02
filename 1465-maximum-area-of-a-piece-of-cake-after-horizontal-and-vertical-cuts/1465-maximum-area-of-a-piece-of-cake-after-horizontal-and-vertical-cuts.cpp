class Solution {
public:
    int mod = 1e9+7;
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
       //int top = 0;
       //int left = 0;
        int mx_w = max(vc[0],w-vc[vc.size()-1]);
        int mx_h = max(hc[0],h-hc[hc.size()-1]);
        for(int i=1;i<hc.size();i++){
            mx_h = max(mx_h,hc[i]-hc[i-1]);
        }
        for(int i=1;i<vc.size();i++){
            mx_w = max(mx_w,vc[i]-vc[i-1]);
        }
        long long res  = (long long)(mx_w) * (long long)(mx_h);
        //ans = ans%mod;
        res = res%mod;
        return res;
    }
};