class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        bool ans = true;
        for(int i = 0;i<matrix.size()-1;i++){
            for(int j = 0;j<matrix[0].size()-1;j++){
                if(matrix[i][j] != matrix[i+1][j+1]){
                    return false;
                }
            }
        }
        return ans;
    }
};