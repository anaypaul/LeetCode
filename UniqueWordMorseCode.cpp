class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> res;
        string code[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        char ch = 'a';
        map<char, string> m;
        m.insert(make_pair(ch, code[0]));
        for(int i = 1;i<26;i++){
            m.insert(make_pair(ch+i, code[i]));
        }
        
        for(int i = 0;i<words.size();i++){
            string x = "";
            for(int j = 0;j<words[i].length();j++){
                x += m[words[i][j]];
            }
            res.insert(x);
            
        }
        return res.size();
    }
};