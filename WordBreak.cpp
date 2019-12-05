class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int i = 0; i<dp.size(); i++){
            for(int j = 0; j<i;j++){
                if(dp[j] && dict.find(s.substr(j, i-j)) != dict.end()){
                    dp[i] = true;
                }
            }
        }
        return dp[dp.size()-1];
        
    }
};