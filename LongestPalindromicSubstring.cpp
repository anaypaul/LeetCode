class Solution {
public:
    int expand(int i, int j, string s){
        int l = i; 
        int r = j;
        while(l>=0 && r<s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        return r - l -1;
    }
    string longestPalindrome(string s) {
        if(s.size() == 0 || s.size() == 1){
            return s;
        } 
        int left = 0;
        int right = 0;
        int maxLen = INT_MIN;
        for(int i = 0; i<s.size(); i++){
            int len1 = expand(i, i, s);
            int len2 = expand(i, i+1, s);
            int len = max(len1, len2);
            maxLen = max(maxLen, len);
            if(len > right - left ){
                left = i - (len-1)/2;
                right = i + len / 2;
            }
        }
        return s.substr(left, maxLen);
    }
};