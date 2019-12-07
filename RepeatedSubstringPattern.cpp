class Solution {
public:
    vector<int> LPS(string s){
        vector<int> lps(s.size(), 0);
        for(int i = 1; i<s.size(); i++){
            int pos = lps[i-1];
            while(pos>0 && s[i]!= s[pos]){
                pos = lps[pos-1];
            }
            if(s[pos] == s[i]){
                lps[i] = pos + 1;
            }
        }
        return lps;
    }
    bool repeatedSubstringPattern(string s) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int> lps = LPS(s);
        int n = s.size();
        int end = lps[lps.size()-1];
        int size = n - end;
        return end && !(end % size);
    }
};