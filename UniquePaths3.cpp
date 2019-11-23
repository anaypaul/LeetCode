class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    bool check(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    void dfs(int i, int j, vector<vector<int>> grid, vector<vector<bool>> vis, int cells, int& res){
        if(check(i, j, grid.size(), grid[0].size()) == false){
            return ;
        }
        if(vis[i][j] == true){
            return ;
        }
        if(grid[i][j] == -1){
            return;
        }
        vis[i][j] = true;
        cells--;
        if(grid[i][j] == 2){
            if(cells == 0){
                res++;
                return;
            }
        }
        for(int idx = 0; idx < 4; idx++){
            int nexti = i + dx[idx];
            int nextj = j + dy[idx];
            dfs(nexti, nextj, grid, vis, cells, res);
        }
        vis[i][j] = false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cells = 0;
        int starti, startj;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    starti = i;
                    startj = j;
                    cells++;
                }
                else if(grid[i][j] == 2){
                    cells++;
                }else if(grid[i][j] == 0){
                    cells++;
                }
            }
        }
        int res = 0;
        dfs(starti, startj, grid, vis, cells, res);
        return res;
    }
};