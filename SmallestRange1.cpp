class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int minv = A[0];
        int maxv = A[0];
        for(auto x: A){
            minv = min(x, minv);
            maxv = max(x, maxv);
        }
        return max(0, maxv - minv - 2*K);
    }
};