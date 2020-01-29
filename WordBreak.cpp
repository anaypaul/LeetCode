//Approach 1:
//Using recursion 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0){
            return true;
        }
        
        for(int i = 1; i<=s.size(); i++){
            string prefix = s.substr(0, i);
            
            if(find(wordDict.begin(), wordDict.end(), prefix) != wordDict.end() && wordBreak(s.substr(i), wordDict)){
                return true;
            }
        }
        return false;
    }
};


//Approach 2 : Solution using trie
class TrieNode{
    public:
    char val;
    vector<TrieNode *> children;
    bool isEnd;
    TrieNode(char ch){
        val = ch;
        vector<TrieNode *> v(26, nullptr);
        children = v;
        isEnd = false;
    }
};
class Solution {
public:
    TrieNode * root;
    Solution(){
        root = new TrieNode('$');
    }
    void insert(string s){
        TrieNode * curr = root;
        for(int i = 0; i<s.size(); i++){
            if(curr->children[s[i]-'a'] == nullptr){
                curr->children[s[i] - 'a'] = new TrieNode(s[i]);
            }
            curr = curr->children[s[i] - 'a'];
        }
        curr->isEnd = true;
    }
    
    bool wordBreak(string s, vector<string>& dict) {
        if(s.size() == 0){
            return true;
        }
        for(auto x : dict){
            insert(x);
        }
        vector<bool> good(s.size()+ 1, false);
        good[0] = true;
        for(int i = 0; i< s.size(); i++){
            if(good[i]){
                TrieNode * curr = root;
                for(int j = i; j<s.size(); j++){
                    if(curr == nullptr){
                        break;
                    }
                    curr = curr->children[s[j] - 'a'];
                    if(curr && curr->isEnd){
                        good[j+1] = true;
                    }
                }
            }
        }
        return good[s.size()];
    }
};

//Approach 3 : Dynamic Programming
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