class Solution {
public:
    string getFirstWord(string s){
        int idx = s.find(" ");
        return s.substr(0, idx);
    }
    string getLastWord(string s){
        int idx = s.find_last_of(" ");
        return s.substr(idx+1);
    }
    bool hasSingleWord(string s){
        int idx = s.find(" ");
        if(idx == -1){
            return true;
        }
        return false;
    }
    string combine(string s1, string s2){ //s1 come before s2
        if(hasSingleWord(s1)  && hasSingleWord(s2)){
            return s1;
        }else if(hasSingleWord(s1) && !hasSingleWord(s2)){
            return s2;
        }else if(!hasSingleWord(s1) && hasSingleWord(s2)){
            return s1;
        }
        int idx = s2.find(" ");
        return s1 + " "+s2.substr(idx+1);
    }
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        unordered_set<string> res;
        unordered_map<string, unordered_set<int>> start_index;
        for(int i = 0; i<phrases.size(); i++){
            start_index[getFirstWord(phrases[i])].insert(i);
        }
        for(int i = 0; i<phrases.size(); i++){
            string lastWord = getLastWord(phrases[i]);
            for(auto each : start_index[lastWord]){
                if(each != i){
                    res.insert(combine(phrases[i], phrases[each]));
                }
            }
        }
        vector<string> result(res.begin(), res.end());
        sort(result.begin(), result.end());
        return result;
    }
};