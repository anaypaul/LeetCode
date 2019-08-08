class Solution {
public:
    
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if(m == 0){
            return m;
        }
        // preprocessing
        vector<int> lps(m, 0);
        for(int i = 1;i<m;i++){
            int pos = lps[i-1];
            while(pos>0 && needle[pos]!=needle[i]){
                pos = lps[pos-1];
            }
            if(needle[pos] == needle[i]){
                lps[i] = pos + 1;
            }
        }
        int idx_haystack = 0;
        int idx_needle = 0;
        for(idx_haystack = 0;idx_haystack<n;idx_haystack++){
            while(idx_needle>0 && needle[idx_needle]!=haystack[idx_haystack]){
                idx_needle = lps[idx_needle-1];
            }
            if(needle[idx_needle] == haystack[idx_haystack]){
                idx_needle++;
            }
            if(idx_needle == m){
                return idx_haystack - m + 1;
            }
        }
        return -1;
        
    }
};