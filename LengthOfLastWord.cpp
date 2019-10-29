class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0){
            return 0;
        }
        int res = 0;
        int i = s.length() - 1;
        while(i>=0 && s[i]== ' '){
            i--;
        }
        while(i>=0 && s[i] != ' '){
            i--;
            res++;
        }
        return res;
    }
};