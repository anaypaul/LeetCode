class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int len = s.size();
        int n = len/numRows;
        int m = ((n-1) * (numRows-2)) + n + 1;
        vector<vector<char>> res(numRows, vector<char>(500, ' ' ));
        string ans = "";
        int idx = 0;
        int i=0, j=0;
        while(idx < len){
            while(idx < len && i<numRows){
                res[i][j] = s[idx];
                i++;
                idx++;
            }
            i--;
            while(idx<len && i>0){
                j++;
                i--;
                res[i][j] = s[idx];
                
                idx++;
            }
            i++;
        }
        for(int i = 0; i< numRows; i++){
            for(int j = 0; j<res[0].size(); j++){
                if(res[i][j] != ' '){
                    ans += res[i][j];
                }
            }
        }
        return ans;
    }
};