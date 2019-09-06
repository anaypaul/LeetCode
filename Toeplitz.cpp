class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        bool ans = true;
        int i = 0, j = 0; 
        while(j<matrix[0].size()){
            int start_i = 0;
            int start_j = j;
            int item = matrix[start_i][start_j];
            while(start_i< matrix.size() && start_j<matrix[0].size()){
                if(item != matrix[start_i][start_j]){
                    return false;
                }
                start_i++;
                start_j++;
            }
            j++;
        }
        i = 1, j = 0;
        while(i< matrix.size()){
            int start_i = i;
            int start_j = 0;
            int item = matrix[start_i][start_j];
            while(start_i< matrix.size() && start_j<matrix[0].size()){
                if(item != matrix[start_i][start_j]){
                    return false;
                }
                start_i++;
                start_j++;
            }
            i++;
        }
        return ans;
    }
};