class Solution {
public:
    void expand(string s, int left, int right, int& res){
        while(left>=0 && right<s.size() && s[left] == s[right]){
            res++;
            left--;
            right++;
        }
    }
    int countSubstrings(string s) {
        std:;ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = s.size();
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            expand(s, i, i, ans);
            expand(s, i, i+1, ans);
        }
        return ans;
    }
};