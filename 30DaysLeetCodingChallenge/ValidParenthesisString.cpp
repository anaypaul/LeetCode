class Solution {
public:
    bool checkValidString(string s) {
        int count = 0;
        // left to right scan
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '*'){
                count++;
            }else{
                count--;
            }
            if(count < 0){
                return false;
            }
        }
        
        if(count == 0){
            return true;
        }
        
        // right to left scan
        count = 0;
        for(int i = s.size()-1; i>=0; i--){
            if(s[i] == ')' || s[i] == '*'){
                count++;
            }else{
                count--;
            }
            if(count < 0){
                return false;
            }
        }
        return true;
    }
};