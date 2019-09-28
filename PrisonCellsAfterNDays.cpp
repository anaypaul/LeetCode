class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<vector<int>> mat(15, vector<int>(8, 0));
        vector<int> curr(cells.begin(), cells.end());
        for(int i = 0;i<mat.size();i++){
            for(int j= 1; j<7;j++){
                mat[i][j] = curr[j-1] == curr[j+1] ? 1 : 0;
            }
            curr.clear();
            for(int j = 0;j<8;j++){
                curr.push_back(mat[i][j]);
            }
        }
        return mat[(N-1)%14];
    }
};