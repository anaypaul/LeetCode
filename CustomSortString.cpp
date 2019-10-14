unordered_map<char, int> um;
class Solution {
public:
    static bool mycmp(char c1, char c2){
        return um[c1] < um[c2];
    }
    string customSortString(string S, string T) {
        vector<char> s(S.begin(), S.end());
        vector<char> t(T.begin(), T.end());
        for(int i = 0; i<s.size(); i++){
            um[s[i]] = i;
        }
        
        sort(t.begin(), t.end(), mycmp);
        string res = "";
        for(auto x : t){
            res = res + x;
        }
        um.clear();
        return res;
    }
};