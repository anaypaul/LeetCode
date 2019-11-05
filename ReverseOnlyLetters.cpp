//Approach 1 : older code.
class Solution {
public:
    string reverseOnlyLetters(string S) {
        stack<char> st;
        for(int i = 0;i<S.length();i++){
            if((S[i]<='z' && S[i]>='a') || (S[i]<='Z' && S[i]>='A')){
                st.push(S[i]);
            }
        }
        string result = "";
        for(int i = 0;i<S.length();i++){
            if((S[i]<='z' && S[i]>='a') || (S[i]<='Z' && S[i]>='A')){
                result = result + st.top();
                st.pop();
            }else{
                result = result + S[i];
            }
        }
        cout<<result;
        return result;
    }

        string reverseOnlyLetters(string S) {
            string res= "";
            for(int i = 0, j= S.length()-1; i< S.length();i++){
                if((S[i]<='z' && S[i]>='a')||(S[i]<='Z' && S[i]>='A')){
                    while( !((S[j]<='z' && S[j]>='a')||(S[j]<='Z' && S[j]>='A'))  ){
                        --j;
                    }
                    res.push_back(S[j]);
                    --j;
                }else{
                    res.push_back(S[i]);
                }
            }
            return res;
        }
};

//Approach 2: new code
class Solution {
public:
    bool check(char ch){
        return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z');
    }
    string reverseOnlyLetters(string S) {
        string res = "";
        int j = S.size()-1;
        for(int i = 0; i<S.size(); i++ ){
            if(check(S[i])){
                while(!check(S[j])){
                    j--;
                }
                char ch = S[j--];
                res = res + ch;
            }else{
                res = res + S[i];
            }
        }
        return res;
    }
};