class Solution {
public:
    int binarySearch(vector<int>& arr, int target){
        int low = 0;
        int high = arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid] == target){
                return mid;
            }else if(arr[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return -1;
    }
    int smallestCommonElement(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int j = 0; j<mat[0].size(); j++){
            int val = mat[0][j];
            bool flag = true;
            for(int i = 1; i<mat.size(); i++){
                if(binarySearch(mat[i], val) == -1){
                    flag = false;
                    break;
                }   
            }
            if(flag){
                return val;
            }
        }
        return -1;
    }
};