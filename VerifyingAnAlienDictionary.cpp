unordered_map<char, int> mp;
class Solution {
public:
    static bool mycmp(string s1, string s2){
        for(int i = 0; i< min(s1.size(), s2.size()); i++){
            if(mp[s1[i]] != mp[s2[i]]){
                return mp[s1[i]] < mp[s2[i]];
            }
        }
        return s1.size() < s2.size();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        mp.clear();
        for(int i = 0; i < 26; i++) mp[order[i]] = i;
        return is_sorted(words.begin(), words.end(), mycmp);
        
    }
};