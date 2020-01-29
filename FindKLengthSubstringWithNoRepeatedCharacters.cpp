class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.size();
        if(k>n){
            return 0;
        }
        int res = 0;
        int hash[26] = {0};
        int types = 0;
        for(int i = 0; i<s.size(); i++){
            if(i<k){
                if(hash[s[i]-'a'] == 0){
                    types++;
                }
                hash[s[i]-'a']++;
            }else{
                hash[s[i-k]-'a']--;
                if(hash[s[i-k]-'a'] == 0){
                    types--;
                }
                
                if(hash[s[i]-'a'] == 0){
                    types++;
                }
                hash[s[i]-'a']++;
            }
            if(types == k){
                //printing the substrings
                // cout<<s.substr(i - k+1, k)<<endl;
                res++;
            }
        }
        return res;
    }
};