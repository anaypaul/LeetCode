class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(A.size() == 0 || A.size()== 1){
            return 0;
        }
        sort(A.begin(), A.end());
        int n = A.size();
        int res = A[n-1] - A[0];
        for(int i = 0; i<A.size()-1; i++){
            int x = A[i];
            int y = A[i+1];
            int tempmax = max(A[n-1]-K, x + K);
            int tempmin = min(A[0] + K, y-K);
            res = min(res, tempmax - tempmin);
        }
        return res;        
    }
};