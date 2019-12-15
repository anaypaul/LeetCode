//TIME OUT SOLUTION
//USING DFS without memonization
class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    bool check(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, int& res, int len, int life){
        int n = grid.size();
        int m = grid[0].size();
        if(check(i, j, n, m) == false){
            return ;
        }
        if(vis[i][j] == true){
            return ;
        }
        if(i == n-1 && j == m-1 && life>=0){
            res = min(res, len);
            return ;
        }
        if(grid[i][j] == 1){
            if(life<1){
                return ;
            }
            vis[i][j] = true;
            for(int idx = 0; idx<4; idx++){
                int nexti = i + dx[idx];
                int nextj = j + dy[idx];
                dfs(nexti, nextj, grid, vis, res, len+1, life-1);
            }
            vis[i][j] = false;
        }
        if(grid[i][j] == 0){
        vis[i][j] = true;
        for(int idx = 0; idx<4; idx++){
            int nexti = i + dx[idx];
            int nextj = j + dy[idx];
            dfs(nexti, nextj, grid, vis, res, len+1, life);
        }
        vis[i][j] = false;
        }
    }
    int shortestPath(vector<vector<int>>& grid, int life) {
        int n = grid.size();
        int m = grid[0].size();
        int res = INT_MAX;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dfs(0, 0, grid, vis, res, 0, life);
        return res==INT_MAX ? -1:res;
    }
};
//Accepted Solution
//DFS with memonization
class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<vector<bool>> vis;
    int dx[4] = {0,1,-1,0};
    int dy[4] = {1,0,0,-1};
    int n;
    int m;
    bool check(int i, int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int dfs(int x, int y, vector<vector<int>>& grid, int k, int moves, int used_k){
        if (used_k > k){
            return INT_MAX;
        }
        if (dp[x][y][used_k] != - 1){
            return dp[x][y][used_k];
        }
        vis[x][y] = true;
        if (x == grid.size() - 1 && y == grid[0].size() - 1){
            return moves;
        }
        int minMoves = INT_MAX;
        for(int idx = 0; idx<4; idx++){
            int nexti = x + dx[idx];
            int nextj = y + dy[idx];
            if(check(nexti, nextj) && !vis[nexti][nextj]){
                minMoves = min(minMoves, dfs(nexti, nextj, grid, k, moves + 1, used_k + grid[nexti][nextj]));
            }
        }
        vis[x][y] = false;
        dp[x][y][used_k] = minMoves;
        return minMoves;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        vis.resize(n, vector<bool>(m, false));
        dp.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        int res = dfs(0, 0, grid, k, 0, 0);
        return res == INT_MAX ? -1 : res;
    }
};
