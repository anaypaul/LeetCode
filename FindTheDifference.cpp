class Solution {
public:
    char findTheDifference(string s, string t) {
        int x = 0;
        for(int i = 0;i<s.length(); i++){
            int m = s[i] - (int)('a');
            x = x ^ m;
        }
        for(int j = 0;j<t.length(); j++){
            int m = t[j] - (int)('a');
            x = x ^ m;
        }
        char ch='a'+x;
        return ch;
    }
};