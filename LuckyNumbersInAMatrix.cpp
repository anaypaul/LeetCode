class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rowD;
        for(int i = 0; i<n; i++){
            rowD.push_back(*min_element(matrix[i].begin(), matrix[i].end()));
        }
        vector<int> colD;
        for(int j = 0; j<m; j++){
            int minVal = matrix[0][j];
            for(int i = 0; i<n; i++){
                minVal = max(minVal, matrix[i][j]);
            }
            colD.push_back(minVal);
        }
        
        for(int i= 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(rowD[i] == colD[j]){
                    res.push_back(rowD[i]);
                }
            }
        }
        return res;
    }
};