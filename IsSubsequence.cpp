class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool res = false;
        int i = 0;
        int j = 0;
        int n = s.length();
        int m = t.length();
        while(i < n  && j < m){
            if(s[i] == t[j]){
                i++;j++;
            }
            else{
                j++;
            }
        }
        if(i == n){
            return true;
        }
        return res;
    }
};