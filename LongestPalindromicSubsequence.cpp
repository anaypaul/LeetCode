//Approach 1 : Top Down with memoization
//Time : O(N*N)
//Space : O(N*N + N)  
class Solution {
public:
    int helper(vector<vector<int>>& dp, string s, int start, int end){
        if(start > end){
            return 0;
        }
        if(start == end){
            return 1;
        }
        if(dp[start][end] == -1){
            if(s[start] == s[end]){
                dp[start][end] = 2 + helper(dp, s, start + 1, end - 1);
            }else{
                int c1 = helper(dp, s, start + 1, end);
                int c2 = helper(dp, s, start, end-1);
                dp[start][end] = max(c1, c2);
            }
        }
        return dp[start][end];
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(),  vector<int>(s.size(), -1));
        return helper(dp, s, 0, s.size()-1);
    }
};

//Approach : Using bottom approach 
//Time : O(N*N)
//Space : O(N*N)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i<n; i++){
            dp[i][i] = 1;
        }
        for(int startIdx = s.size()-1; startIdx >=0 ; startIdx--){
            for(int endIdx = startIdx + 1; endIdx < n; endIdx++){
                if(s[startIdx] == s[endIdx]){
                    dp[startIdx][endIdx] = 2 + dp[startIdx+1][endIdx-1];
                }else{
                    dp[startIdx][endIdx] = max(dp[startIdx + 1][endIdx], dp[startIdx][endIdx-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};