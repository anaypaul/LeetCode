class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> str;
        for(auto x:s){
            str.push_back(x);
        }
        stack<int> st;
        for(int i = 0;i<str.size(); i++){
            if(str[i] == '('){
                st.push(i);
            }else if(str[i] == ')'){
                int start = st.top();
                int end = i;
                st.pop();
                while(start<=end){
                    char t = str[start];
                    str[start] = str[end];
                    str[end] = t;
                    start++;
                    end--;
                }
            }
        }
        string res = "";
        for(auto x : str){
            if(x!='(' && x!=')'){
                res += x;
            }
        }
        return res;
    }
};