class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    bool check(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int dfs(int i, int j, int sum , vector<vector<int>>& grid, vector<vector<bool>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        res = max(res, sum);
        int x = 0;
        vis[i][j] = true;
        for(int idx = 0; idx<4; idx++){
            int ni = i + dx[idx];
            int nj = j + dy[idx];
            if(check(ni, nj, n, m) && grid[ni][nj] != 0 && !vis[ni][nj]){
                x = dfs(ni, nj, sum + grid[ni][nj], grid, vis);
                res = max(res, x);
            }
        }
        vis[i][j] = false;
        return res;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res= 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] != 0){
                    vector<vector<bool>> vis(n, vector<bool>(m, false));
                    int ans = dfs(i, j, grid[i][j], grid, vis);
                    res = max(ans, res);
                }
            }
        }
        return res;
    }
};