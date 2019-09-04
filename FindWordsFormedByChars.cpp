class Solution {
public:
    bool check(string s, map<char, int> m){
        map<char, int> temp;
        for(int i = 0;i<s.length();i++){
            if(temp.find(s[i]) == temp.end()){
                temp.insert(make_pair(s[i],1));
            }else{
                temp[s[i]] += 1;
            }
        }
        bool res = true;
        for(int i = 0;i<s.length();i++){
            if(m.find(s[i]) != m.end() && m[s[i]] >= temp[s[i]]){
                continue;
            }else{
                res = false;
                break;
            }
        }
        return res;
    }
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> m;
        for(int i = 0;i<chars.length();i++){
            if(m.find(chars[i]) == m.end()){
                m.insert(make_pair(chars[i], 1));
            }else{
                m[chars[i]] += 1;
            }
        }
        int res = 0;
        for(auto x : words){
            if(check(x, m)){
                res += x.length();
            }
        }
        return res;
    }
};