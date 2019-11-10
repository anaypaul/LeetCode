class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(auto x : indices){
            for(int i = 0; i<n; i++){
                mat[i][x[1]]++;
            }
            for(int j = 0; j<m; j++){
                mat[x[0]][j]++;
            }
        }
        int res= 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ; j++){
                if(mat[i][j]%2==1){
                    res++;
                }
            }
        }
        return res;
    }
};