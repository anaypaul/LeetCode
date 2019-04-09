class Solution {
public:
    string removeOuterParentheses(string S) {
        vector<string> res;
        bool isBalanced = false;
        int counter = 0;
        string s_temp = "";
        for(int i =0;i<S.length();i++){
            s_temp += S[i];
            if(S[i] == '('){
                counter++;
            }
            else if(S[i] == ')'){
                counter--;
            }
            if(counter == 0){
                res.push_back(s_temp);    
                s_temp = "";
            }
        }
        string answer = "";
        for(auto x : res){
            for(int i = 1;i<x.length()-1;i++){
                answer += x[i];
            }
        }
        return answer;
    }
};