class Solution {
public:
    string getCode(string s){
        string res = "";
        vector<int> hash(26, 0);
        for(int i = 0; i<s.size(); i++){
            hash[s[i] - 'a']++;
        }
        for(int i = 0; i<hash.size(); i++){
            res += to_string(hash[i]);
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<int>> m;
        for(int i = 0; i<strs.size();i++){
            string c = getCode(strs[i]);
            m[c].push_back(i);
        }
        for(auto each : m){
            vector<string> t;
            for(auto i : each.second){
                t.push_back(strs[i]);
            }
            res.push_back(t);
        }
        return res;
    }
};