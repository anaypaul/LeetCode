class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int res = 0;
        int term1 = 0;
        for(int i = 0; i<A.size(); i++){
            res = max(res, term1 + A[i] - i);
            term1 = max(term1, A[i] + i);
        }
        return res;
    }
};