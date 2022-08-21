class Solution {
public:
    string dq2(deque<char> dq){
        string ans = "";
        while(!dq.empty()){
            ans += dq.front();
            dq.pop_front();
        }
        return ans;
    }
    string largestPalindromic(string num) {
     priority_queue<pair<char,int>,vector<pair<char,int>>, greater<pair<int,int>>> pq;
     priority_queue<pair<char,int>> pqod;
    deque<char> dq;
        map<char,int> mp;
        for(int i=0;i<num.length();i++){
            mp[num[i]]++;
        }
        for(auto it:mp){
            if(it.second%2 == 0){
                pq.push({it.first,it.second});
            }
            else{
                pqod.push({it.first,it.second});
            }
        }
        
        if(!pqod.empty()){
            pair<char,int> temp;
            temp = pqod.top();
            dq.push_back(temp.first);
            pqod.pop();
           temp.second--;
           if(temp.second!=0) pq.push(temp);
        }
        while(!pqod.empty()){
            pair<char,int> x = pqod.top();
            pqod.pop();
            if(x.second>1){
                pq.push({x.first,x.second-1});
            }
        }
        if(!pq.empty() && pq.top().first == '0' && pq.size() == 1) {
            if(dq.empty()) dq.push_back('0');
            return dq2(dq);
        }
        while(!pq.empty()){
            pair<char,int> t = pq.top();
            pq.pop();
           int j = t.second/2;
            while(j--){
                dq.push_back(t.first);
            }
            j = t.second/2;
            while(j--){
                dq.push_front(t.first);
            }
        }
        return dq2(dq);
    }
};