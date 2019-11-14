class Solution {
public:
    void dfs(int i, string digits, unordered_map<char, vector<char>> um, vector<string>& res, string& temp){
        if(i == digits.size()){
            res.push_back(temp);
            return ;
        }
        for(auto each : um[digits[i]]){
            temp = temp + each;
            dfs(i+1, digits, um, res, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(digits.size()==0){
            return {};
        }
        unordered_map<char, vector<char>> um{
            {'1', {}},
            {'2', {'a','b','c'}},
            {'3', {'d','e','f'}},
            {'4', {'g','h','i'}},
            {'5', {'j','k','l'}},
            {'6', {'m','n','o'}},
            {'7', {'p','q','r','s'}},
            {'8', {'t','u','v'}},
            {'9', {'w','x','y','z'}},
        };
        vector<string> res;
        string temp = "";
        dfs(0, digits, um, res, temp);
        return res;
    }
};