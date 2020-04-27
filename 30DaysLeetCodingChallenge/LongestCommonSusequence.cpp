class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(m == 0 || n == 0){
            return 0;
        }
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i = 0; i<n+1; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j<m+1; j++){
            dp[0][j] = 0;
        }
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                dp[i][j] = (s1[i-1] == s2[j-1] ? 1 + dp[i-1][j-1] : max(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[n][m];
    }
};