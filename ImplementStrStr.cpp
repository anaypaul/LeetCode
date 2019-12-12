// KMP Algorithm
// Time complexity : Linear time O(n)
class Solution {
public:
    int strStr(string text, string pattern) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int text_l = text.size();
        int pat_l = pattern.size();
        if(pat_l == 0){
            return 0;
        }
        vector<int> lps(pat_l, 0);
        for(int i = 1; i<pat_l; i++){
            int pos = lps[i-1];
            while(pos > 0 && pattern[pos]!= pattern[i]){
                pos = lps[pos-1];
            }
            if(pattern[pos] == pattern[i]){
                lps[i] = pos + 1;
            }
        }
        int idx_p = 0;
        int idx_t = 0;
        for(idx_t = 0; idx_t<text_l; idx_t++){
            while(idx_p > 0 && pattern[idx_p] != text[idx_t]){
                idx_p = lps[idx_p-1];
            }
            if(text[idx_t] == pattern[idx_p]){
                idx_p++;
            }
            if(idx_p == pat_l){
                return idx_t - pat_l + 1;
            }
        }
        return -1;
    }
};