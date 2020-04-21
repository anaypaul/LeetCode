/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int res = INT_MAX;
        vector<int> size = binaryMatrix.dimensions();
        int n = size[0];
        int m = size[1];
        bool found = false;
        for(int i = 0; i<n; i++){
            //apply binary search for ith row to get 1
            int low = 0;
            int high = m-1;
            int colNum = INT_MAX;
            while(low<=high){
                int mid = low + (high - low)/2;
                if(binaryMatrix.get(i, mid) == 1){
                    colNum = min(colNum, mid);
                    high = mid-1;
                }else{
                    low = mid + 1;
                }
            }
            res = min(res, colNum);
        }
        return res == INT_MAX ? -1 : res;
    }
};