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

//Using dynamic programming
class Solution {
public:
    string longestPalindrome(string s) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = s.size();
        if(n == 1 || n == 0){
            return s;
        }
        vector<vector<bool>> dp(n , vector<bool>(n , true));
        for(int i = 0; i<n; i++){
            dp[i][i] = true;
        }
        
        int maxLen = 1;
        int start = 0;
        for(int l = 1; l<n; l++){
            for(int i = 0; i + l<n; i++){
                int j = i + l;
                if(j - i + 1 == 2){
                    dp[i][j] = s[i] == s[j];
                }else{
                    dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
                }
                if(dp[i][j] && maxLen < j - i + 1){
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};