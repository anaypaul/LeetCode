class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = A.size();
        unordered_set<int> um;
        for(auto x : A){
            um.insert(x);
        }
        int res = 0;
        for(int i = 0; i<n-1; i++){
            for(int j = i + 1; j<n; j++){
                int term1 = A[i];
                int term2 = A[j];
                int curr_len = 2;
                int target = term1 + term2;
                while(um.find(target) != um.end()){
                    term1 = term2;
                    term2 = target;
                    curr_len++;
                    res = max(res, curr_len);
                    target = term1 + term2;
                }
            }
        }
        return res;
    }
};