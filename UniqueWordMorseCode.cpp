class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<char, string> mymap;
        string codes[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        char abc[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        for(int i = 0;i<26;i++){
            mymap.insert(make_pair(abc[i], codes[i]));
        }
        set<string> s;
        for(int i = 0;i<words.size();i++){
            string x = words[i];
            string ss ="";
            for(int j = 0;j<x.length();j++){
                ss = ss + mymap[x[j]];
            }
            s.insert(ss);
        }
        return s.size();

    }
};