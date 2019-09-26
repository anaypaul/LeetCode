class Solution {
public:
    string removeBacks(string S){
        stack<char> st;
        for(int i = 0;i<S.length(); i++){
            if(S[i] == '#'){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                st.push(S[i]);
            }
        }
        string res ="";
        while(!st.empty()){
            res = st.top()+res ;
            st.pop();
        }
        return res;
    }
    bool backspaceCompare(string S, string T) {
        string str1 = removeBacks(S);
        string str2 = removeBacks(T);
        return str1.compare(str2)==0;
    }
};