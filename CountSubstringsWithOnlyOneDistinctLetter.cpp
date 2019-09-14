class Solution {
public:
    int countLetters(string S) {
        int res = 0;
        char prev = S[0];
        int len = 1;
        for(int i = 1;i<S.length(); i++){
            if(prev == S[i]){
                len++;
            }else{
                res += (len*(len+1))/2;
                prev = S[i];
                len=1;
            }
        }
        res += (len*(len+1))/2;
        return res;
    }
};