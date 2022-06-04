class Solution {
public:
    vector<int> dp;
    int help(vector<int>& days, vector<int>& costs, int si, int finalday){
        if(si==days.size()) return 0;
        
        if(days[si]<=finalday){
            return help(days,costs,si+1,finalday);
        } 
        
        if(dp[si]!=-1){
            return dp[si];
        }
        int a = costs[0] + help(days,costs,si+1,days[si]);
        int b = costs[1] + help(days,costs,si+1,days[si]+6);
        int c = costs[2] + help(days,costs,si+1,days[si]+29);
        
        return dp[si] = min(a,min(b,c));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size(),-1);
        return help(days,costs,0,0);
    }
};
