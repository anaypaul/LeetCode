class Solution {
public:
    bool check(char c){
        return c=='A' || c=='E' || c=='I' || c=='O' || c =='U' || c=='a' || c=='e' || c=='i' || c=='o' || c =='u';
    }
    string reverseVowels(string s) {
        string res = "";
        stack<char> st;
        for(int i = 0;i<s.size(); i++){
            if(check(s[i])){
                st.push(s[i]);
            }
        }
        for(int i = 0;i<s.length(); i++){
            if(check(s[i])){
                res += st.top();
                st.pop();
            }
            else{
                res += s[i];
            }
        }
        return res;
    }
};