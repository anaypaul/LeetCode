class Solution {
public:
    int helper(vector<int> A, int low, int high){
        while(low < high){
            int mid = low + (high-low)/2;
            if(A[mid] >= mid){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        if(A[low]!=low){
            return -1;
        }
        return low;
    }
    int fixedPoint(vector<int>& A) {
        return helper(A, 0, A.size());
    }
};