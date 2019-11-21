class Solution {
public:
    bool check(char ch){
        return ch>='a' && ch<='z' || ch>='A' && ch<='Z';
    }
    void dfs(string s, unordered_set<string>& res, string temp, int index){
        if(index == s.size()){
            res.insert(temp);
            return;
        }
        if(check(s[index])){
            char ch_l = (char)tolower(s[index]);
            char ch_u = (char)toupper(s[index]);
            dfs(s, res, temp + ch_l , index + 1);
            dfs(s, res, temp + ch_u , index + 1);
        }
        dfs(s, res, temp + s[index], index + 1);
    }
    vector<string> letterCasePermutation(string S) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_set<string> res;
        string s="";
        dfs(S, res, s, 0);
        vector<string> temp(res.begin(), res.end());
        return temp;
    }
};