class Solution {
public:
    bool checkRecord(string s) {
        int lates = 0;
        int absents = 0;
        for(int i = 0;i<s.length(); i++){
            if(s[i] == 'P'){
                lates = 0;
            }
            else if(s[i] == 'A'){
                absents++;
                lates = 0;
            }else if(s[i] == 'L'){
                lates++;
            }
            if(absents>1 || lates>2){
                return false;
            }
        }
        return true;
    }
};