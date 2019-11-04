class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        if(s.size() == 0){
            return res;
        }
        for(int i = 0; i<s.size(); i++){
            if(s[i] != ' '){
                res++;
                while(i+1<s.size() && s[i+1] != ' '){
                    i++;
                }
            }
        }
        return res;
    }
};