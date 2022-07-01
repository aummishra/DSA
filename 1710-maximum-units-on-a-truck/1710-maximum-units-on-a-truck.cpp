class Solution {
public:
    static bool myComp(pair<int,int> a, pair<int,int> b){
            return b.second < a.second;
    }
    int maximumUnits(vector<vector<int>>& box, int truckSize) {
        int total_unit =0;
        vector<pair<int,int>> boxTypes;
        for(auto it:box){
            boxTypes.push_back({it[0],it[1]});
        }
          sort(boxTypes.begin(),boxTypes.end(),myComp);
          int i=0;
        while(truckSize!=0 && i<boxTypes.size()){
            if(boxTypes[i].first <= truckSize){
                total_unit += boxTypes[i].first * boxTypes[i].second;
                truckSize -= boxTypes[i].first;
            }
            else{
                total_unit += truckSize * (boxTypes[i].second );
                truckSize =0;
            }
            i++;
        }
    return total_unit;
    } 
};