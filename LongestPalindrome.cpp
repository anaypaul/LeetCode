class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> um;
        for(auto x: s){
            um[x]++;
        }
        int res = 0;
        int oddLengthMax = 0;
        for(auto x : um){
            res += x.second/2 * 2;
            if(res%2 == 0 && x.second%2 == 1){
                res++;
            }
        }
        return res;
    }
};