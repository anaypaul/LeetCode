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

//Approach 2 : topdown with memoization 
// memory limit exceeds
// time : O(n * n)
// space : O(n * n  + n)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0 || s.size() == 1){
            return s;
        }
        int n = s.size();
        string res = "";
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        helper(s, 0, n-1, dp, res);
        return res;
    }
    int helper(string s, int start, int end, vector<vector<int>>& dp, string& res){
        if(start > end){
            return 0;
        }
        if(start == end){
            return 1;
        }
        if(dp[start][end] == -1){
            int c1 = 0;
            if(s[start] == s[end]){
                int r = end - start -1;
                if(r == helper(s, start + 1, end -1 , dp, res)){
                    c1 =  r + 2;
                }
            }
            int c2 = helper(s, start + 1, end , dp, res);
            int c3 = helper(s, start , end - 1, dp, res);
            int x = max(c1, max(c2, c3));
            if(res.size() < x){
                res = s.substr(start, x);
            }
            dp[start][end] = x;
        }
        return dp[start][end];
    }
};