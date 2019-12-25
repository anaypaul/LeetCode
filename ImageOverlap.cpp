class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int res = 0;
        int n = A.size();
        int m = A[0].size();
        vector<vector<int>> mat(3 * n , vector<int>(3*m,0));
        
        int basei = n;
        int basej = m;
        for(int k= 0; k<n; k++){
            for(int l=0; l<m; l++){
                mat[basei + k][basej + l] = A[k][l];
            }
        }
        
        for(int i = 0; i<3*n - n; i++){
            for(int j = 0; j<3*m - m; j++){
                int basei = i;
                int basej = j;
                int count = 0;
                for(int k = 0; k<n; k++){
                    for(int l = 0; l<m; l++){
                        if(mat[basei+k][basej+l] == B[k][l] && B[k][l] == 1){
                            count++;
                        }
                    }
                }
                res = max(res, count);
            }
        }
        return res;
    }
};