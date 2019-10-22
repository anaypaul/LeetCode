class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> rows(n , false);
        vector<bool> cols(m, false);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0){
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        for(int i = 0; i<rows.size(); i++){
            if(rows[i]){
                for(int j = 0; j<m; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 0; j<cols.size(); j++){
            if(cols[j]){
                for(int i = 0; i<n;i++){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};