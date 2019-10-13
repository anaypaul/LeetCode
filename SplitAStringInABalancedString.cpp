class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int i = 0;
        int L = 0;
        int R = 0;
        while(i<s.length()){
            if(s[i] == 'L'){
                L++;
            }
            if(s[i] == 'R'){
                R++;
            }
            if(L== R){
                ans++;
                L = 0;
                R = 0;
            }
            i++;
        }
        return ans;
    }
};