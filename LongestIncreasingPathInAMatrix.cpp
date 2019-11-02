//Approach 1: By applying DFS starting from all cell of the matrix.
// [Memory limit exceeded]
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
class Solution {
public:
    bool check(int i, int j, int n, int m){
        return i>=0 && j >=0 && i< n && j<m;
    }
    void dfs(int i, int j, vector<vector<int>> mat, vector<vector<bool>>& vis, int prev, int& len, int & res){
        int n = mat.size();
        int m = mat[0].size();
        if(check(i, j, n, m ) == false){
            return;
        }
        if(mat[i][j] <= prev){
            return;
        }
        if(vis[i][j]){
            return;
        }
        vis[i][j] = true;
        len++;
        res = max(res, len);
        for(int idx = 0; idx<4; idx++){
            dfs(i + dx[idx], j+ dy[idx], mat, vis, mat[i][j], len, res);
        }
        vis[i][j] = false;
        len--;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0){
            return 0;
        }
        int m = matrix[0].size();
        int res = INT_MIN;
        int ans = 0;
        vector<vector<bool>> vis(n , vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int prev = INT_MIN;
                int len = 0;
                int res = 0;
                dfs(i, j, matrix, vis, prev, len, res);
                ans = max(ans , res);
                
            }
        }
        return ans; 
    }
};