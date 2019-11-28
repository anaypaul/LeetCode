class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int i = 0; int j = A.size()-1;
        int sum = A[i] + A[j];
        int res = INT_MIN;
        while(i<j){
            if(sum >= K){
                j--;
            }else{
                i++;
                res = max(res, sum);
            }
            sum = A[i] + A[j];
        }
        return res == INT_MIN ? -1 : res;
    }
};