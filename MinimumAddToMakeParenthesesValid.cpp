class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int openings=0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else{
                if(!st.empty()){
                    st.pop();
                }else{
                    openings++;
                }
            }
        }
        return st.size() + openings;
    }
};