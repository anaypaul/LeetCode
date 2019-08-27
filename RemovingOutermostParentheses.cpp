class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans = "";
        bool outer = true;
        int open = 0;
        for(int i = 0;i<S.length();i++){
            if(outer && S[i] == '('){
                outer = false;
            }
            else{
                if(S[i] == '('){
                    ans += '(';
                    open++;
                }else if(S[i] == ')' && open ==0){
                    outer = true;
                }else if(S[i] == ')' && open > 0){
                    ans += ')';
                    open--;
                }
            }
        }
        return ans;
    }
};