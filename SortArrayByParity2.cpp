class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int even = 0;
        for(int i = 0;i<A.size();i++){
            if(A[i]%2==0 && i%2==1){
                int t = A[i];
                A[i] = A[even];
                A[even] = t;
                even = even + 2;
                i--;
            }
        }
        return A;
    }
};