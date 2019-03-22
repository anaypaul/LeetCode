class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        int left = 0;
        int right = 0;
        for(int i = 0; i< A.size();i++){
            if(A[i]<0){
                right++;
                A[i] = A[i] * A[i];
            }
        }
        left = right -1;
        for(int i = right;i<A.size();i++){
            if(A[i] == 0){
                res.push_back(0);
                right++;
            }
        }
        for(int i = right;i<A.size();i++){
            A[i] = A[i]*A[i];
        }
        while(left>=0 && right<A.size()){
            if(A[left] <= A[right]){
                res.push_back(A[left]);
                left--;
            }else{
                res.push_back(A[right]);
                right++;
            }
        }
        while(left>=0){
            res.push_back(A[left--]);
        }
        while(right<A.size()){
            res.push_back(A[right++]);
        }
        return res;
    }
};