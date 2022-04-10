class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C"){
                st.pop();
            }
            else if(ops[i]=="D"){
                int a = st.top();
                st.push(2*a);
            }
            else if(ops[i]=="+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a+b);
            }
            else{
                st.push(stoi(ops[i]));
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        return ans;
    }
};