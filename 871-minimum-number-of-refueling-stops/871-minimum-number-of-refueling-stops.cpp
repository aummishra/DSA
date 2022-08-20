class Solution {
public:
    static bool myComp(pair<int,int> a, pair<int,int>b){
        return a.first < b.first;
    }
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(stations.size() == 0){
            if(startFuel >= target){
                return 0;
            }
            else{
                return -1;
            }
        }
        vector<pair<int,int>> v;
        for(auto it: stations){
            v.push_back({it[0],it[1]});
        }
        priority_queue<int> pq;
        bool flag =0;
        sort(v.begin(),v.end(),myComp);
        int total_fuel = startFuel;
        int count =0;
        for(int i=0;i<v.size();i++){
            if(total_fuel >= target){
                break;
            }
           while(total_fuel < v[i].first){
               if(pq.empty()){
                 flag =1;
                   count = -1;
                   break;
               } total_fuel += pq.top();
               pq.pop();
               count++;
           }
            if(flag){
                break;
            }
            pq.push(v[i].second);
        }
        if(flag){
            return -1;//count
        }
            while(total_fuel<target && !pq.empty()){
                total_fuel += pq.top();
                pq.pop();
                count++;
            }
            if(total_fuel<target){
               return -1;
            }
        return count;
    }
};