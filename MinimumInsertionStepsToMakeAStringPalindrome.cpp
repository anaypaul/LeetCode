class Solution {
public:
    int minInsertions(string s) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(s.size() == 0 || s.size() == 1){
            return 0;
        }
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(s[i] == s[n-1-j]){
                    dp[i+1][j+1] = dp[i][j] + 1; 
                }else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return n - dp[n][n];
    }
};