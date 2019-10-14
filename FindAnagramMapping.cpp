class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res(A.size(), -1);
        unordered_map<int,int> um;
        for(int i = 0; i<B.size(); i++){
            um[B[i]] = i;
        }
        for(int i = 0; i< res.size(); i++){
            res[i] = um[A[i]];
        }
        return res;
    }
};