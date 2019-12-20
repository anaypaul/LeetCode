class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<string> res;
        unordered_set<string> dict(words.begin(), words.end());
        for(auto word : words){
            int n = word.size();
            if(n == 0){
                continue;
            }
            bool dp[n+1];
            memset(dp, false, sizeof(dp));
            dp[0] = true;
            for(int i = 0; i<n; i++){
                if(dp[i] == false){
                    continue;
                }
                string generate = "";
                for(int j = i; j<n; j++){
                    generate += word[j];
                    if(dp[j+1] == true){
                        continue;
                    }
                    if(i == 0 && j == n-1){
                        continue;
                    }
                    if(dict.find(generate) != dict.end()){
                        dp[j+1] = true;
                    }
                }
                if(dp[n]){
                    res.push_back(word);
                    break;
                }
            }
        }
        
        
        return res;
    }
};