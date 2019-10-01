class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int start = -1;
        int end = -1;
        for(int i = 0;i<s.length(); ){
            start = i;
            while(s[i] == s[start]){
                i++;
            }
            if(i-start >=3){
                res.push_back({start, i-1});
            }
        }
        return res;
    }
};