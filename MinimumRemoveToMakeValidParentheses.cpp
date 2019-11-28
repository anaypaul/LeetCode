class Solution {
public:
    string minRemoveToMakeValid(string s) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        string res = "";
        stack<pair<char,int>> st;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '(' || s[i] ==')'){
                st.push(make_pair(s[i], i));
            }
        }
        vector<bool> invalid(s.size(), false);
        stack<pair<char, int>> st2;
        while(!st.empty()){
            if(st.top().first == ')'){
                st2.push(st.top());
                st.pop();
            }else if(st.top().first == '('){
                if(st2.empty()){
                    invalid[st.top().second] = true;
                    st.pop();
                }else{
                    st2.pop();
                    st.pop();
                }
            }
        }
        if(!st2.empty()){
            while(!st2.empty()){
                invalid[st2.top().second] = true;
                st2.pop();
            }
        }
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='(' || s[i] ==')'){
                if(invalid[i]){
                    continue;
                }else{
                    res += s[i];
                }
            }else{
                res += s[i];
            }
        }
        return res;
    }
};