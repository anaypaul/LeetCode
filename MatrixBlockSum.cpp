class Solution {
public:
    bool check(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), 0));
        for(int i = 0; i<mat.size(); i++){
            for(int j= 0; j<mat[0].size(); j++){
                int sum = 0;
                int starti = i - K;
                int startj = j - K;
                int endi = i + K;
                int endj = j + K;
                for(int idxi = starti; idxi<= endi; idxi++){
                    for(int idxj = startj; idxj<= endj; idxj++){
                        if(check(idxi, idxj, mat.size(), mat[0].size())){
                            sum += mat[idxi][idxj];
                        }
                    }
                }
                res[i][j] = sum;
            }
        }
        return res;
    }
};