class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(int i = 0;i<s.length(); i++){
            if(st.empty()){
                st.push(make_pair(s[i], 1));
            }
            else{
                if(st.top().first == s[i]){
                    int c = st.top().second;
                    st.push(make_pair(s[i], c+1));
                    if(!st.empty() && st.top().second == k){
                        for(int j = 0; !st.empty() && j<k; j++){
                            st.pop();
                        }
                    }
                }else{
                    st.push(make_pair(s[i], 1));
                }
            }
        }
        string ch="";
        while(!st.empty()){
            ch = st.top().first + ch;
            st.pop();
            
        }
        return ch;
    }
};