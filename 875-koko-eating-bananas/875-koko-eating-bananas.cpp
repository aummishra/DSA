class Solution {
public:
    int count(vector<int>& piles,int mid){
        int cnt = 0;
         for(int i=0;i<piles.size();i++){
         if(piles[i]<=mid) cnt++;
         else if(piles[i]%mid == 0) cnt+= piles[i]/mid;
         else cnt+= piles[i]/mid + 1;
       } 
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = 1e9;
        int low = 1;
        int ans;
        int res = INT_MAX;
        //int mid = (high+low)/2;
        while(low<high ){
           int mid = (high+low)/2;
           // cout<<mid<<" "<<endl;
             if(count(piles,mid)>h){
                low = mid+1;
            }
            else {
                high = mid;
            }
        }     
        return low;
    }
};