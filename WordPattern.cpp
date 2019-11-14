class Solution {
public:
    bool wordPattern(string pattern, string str) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int len = pattern.size();
        vector<int> patSame(len, -1);
        unordered_map<char, int> m;
        for(int i = 0; i<pattern.size(); i++){
            if(m.find(pattern[i]) == m.end()){
                m[pattern[i]] = i;
                patSame[i] = m[pattern[i]];
            }else{
                int index = m[pattern[i]];
                patSame[i] = patSame[index];
                m[pattern[i]] = i;
            }
        }
        stringstream ss(str);
        vector<string> strings;
        string temp;
        while(getline(ss, temp, ' ')){
            strings.push_back(temp);
        }
        int len1 = strings.size();
        if(len != len1){
            return false;
        }
        unordered_map<string, int> m1;
        vector<int> stringSame(len1);
        for(int i = 0; i<strings.size(); i++){
            if(m1.find(strings[i]) == m1.end()){
                m1[strings[i]] = i;
                stringSame[i] = m1[strings[i]];
            }else{
                int index = m1[strings[i]];
                stringSame[i] = stringSame[index];
                m1[strings[i]] = i;
            }
        }
        for(int i = 0; i<len; i++){
            if(patSame[i] != stringSame[i]){
                return false;
            }
        }
        return true;
    }
};