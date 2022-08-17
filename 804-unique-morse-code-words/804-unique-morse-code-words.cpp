class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
       set<string> st;
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto it:words){
            string temp = "";
            for(int i=0;i<it.length();i++){
                temp += v[it[i]-'a'];
            }
            st.insert(temp);
        }
            return st.size();
    }
};