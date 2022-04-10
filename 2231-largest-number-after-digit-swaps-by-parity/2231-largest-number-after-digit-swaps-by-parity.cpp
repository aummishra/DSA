class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> pq1;
        priority_queue<int> pq2;
        string t = to_string(num);
        for(int i=0;i<t.length();i++){
            if(t[i]%2==0){
                pq2.push(t[i]);
            }
            else if(t[i]%2!=0){
                pq1.push(t[i]);
            }
        }
        for(int i=0;i<t.length();i++){
            if(t[i]%2==0){
                t[i] = pq2.top();
                pq2.pop();
            }
            else if(t[i]%2!=0){
                t[i] = pq1.top();
                pq1.pop();
            }
        }
        return stoi(t);
    }
};