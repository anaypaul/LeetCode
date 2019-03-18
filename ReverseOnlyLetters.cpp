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