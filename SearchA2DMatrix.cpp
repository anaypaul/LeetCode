class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() ){
            return false;
        }
        if(matrix.size()==0 || matrix[0].size()==0){
                return false;
        }
        int i;
        bool res = false;
        int top = 0;
        int bottom = matrix.size() - 1;
        while(top<= bottom){
            int mid = top + (bottom-top)/2;
            if(matrix[mid][0]<= target && target <= matrix[mid][matrix[mid].size()-1]){
                i = mid;
                break;
            }else if(matrix[mid][0] > target){
                bottom--;
            }else{
                top++;
            }
        }
        int low = 0;
        int high = matrix[i].size() - 1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[i][mid] == target){
                res = true;
                break;
            }else if(matrix[i][mid] > target){
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }
        return res;
    }
};