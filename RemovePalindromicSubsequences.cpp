class Solution {
public:
    
    bool check(string s){
        string t = s;
        reverse(t.begin(), t.end());
        if(t.compare(s) == 0){
            return true;
        }
        return false;
    }
    int removePalindromeSub(string s) {
        if(s.size() == 0){
            return 0;
        }
        if(s.size() == 1){
            return 1;
        }
        if(check(s)){
            return 1;
        }
        int counta = 0;
        int countb = 0;
        for(auto x : s){
            if(x == 'a'){
                counta++;
            }else{
                countb++;
            }
        }
        int step = 0;
        if(counta > 0 && countb > 0){
            return 2;
        }else{
            return 1;   
        }
       return step;
    }
};