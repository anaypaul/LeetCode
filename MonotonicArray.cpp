class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool res1 = true;
        //check increasing
        for(int i = 0;i < A.size() - 1; i++){
            if(A[i]<= A[i+1]){
                res1 = true;
            }else{
                res1 = false;
                break;
            }
        }
        //check decreasing
        bool res2 = true;
        for(int i = 0;i<A.size()-1;i++){
            if(A[i] >= A[i+1]){
                res2 = true;
            }else{
                res2 = false;
                break;
            }
        }
        if(res2 || res1){
            return true;
        }
        return false;
    }
};