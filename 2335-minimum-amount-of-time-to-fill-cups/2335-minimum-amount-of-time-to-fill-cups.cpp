class Solution {
public:
    int fillCups(vector<int>& amt) {
     priority_queue<int> pq;
        int ans = 0;
        for(auto &it: amt) 
        {     if(it == 0)continue;
            pq.push(it);
        }
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            a--;
            b--;
            ans++;
            if(a!=0)
            pq.push(a);
            if(b!=0)
            pq.push(b);
        }
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};