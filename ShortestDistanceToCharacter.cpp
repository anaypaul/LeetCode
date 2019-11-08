class Solution {
public:
    bool check(int i, int n){
        return i>=0 && i<n;
    }
    vector<int> shortestToChar(string s, char c) {
        vector<int> dp(s.size(),INT_MAX);
        queue<int> q;
        for(int i = 0; i<s.size(); i++){
            if(c == s[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x = q.size();
            for(int i = 0; i<x; i++){
                auto t = q.front();
                int level = 0;
                for(int j = t; j>=0; j--){
                    dp[j] = min(dp[j], level);
                    level++;
                }
                level = 0;
                for(int j = t; j<s.size(); j++){
                    dp[j] = min(dp[j], level);
                    level++;
                }
                q.pop();
            }
        }
        return dp;
    }
};