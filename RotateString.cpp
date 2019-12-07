class Solution {
public:
    int KMP(string s, string pattern){
        int text_l = s.size();
        int pat_l = pattern.size();
        if(pat_l == 0){
            return pat_l;
        }
        //preprocessing to get LPS
        vector<int> lps(pat_l, 0);
        for(int i = 1; i<pat_l; i++){
            int pos = lps[i-1];
            while(pos>0 && pattern[pos] != pattern[i]){
                pos = lps[pos-1];
            }
            if(pattern[pos] == pattern[i]){
                lps[i] = pos+1;
            }
        }
        
        int idx_t = 0;
        int idx_p = 0;
        for(idx_t = 0; idx_t< text_l; idx_t++){
            while(idx_p > 0 && pattern[idx_p] != s[idx_t]){
                idx_p = lps[idx_p-1];
            }
            if(pattern[idx_p] == s[idx_t]){
                idx_p++;
            }
            if(idx_p == pat_l){
                return idx_t - pat_l  + 1;
            }
        }
        return -1;
    }
    bool rotateString(string A, string B) {
        if(A.size()!= B.size()){
            return false;
        }
        if(A.size() == 0){
            return true;
        }
        string x = A + A;
        int index = KMP(x, B);
        if(index == -1){
            return false;
        }
        return true;
    }
};