int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
class Solution {
public:
    bool check(int i,int j, int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int dfs(vector<vector<int>> grid, int start_i, int start_j, int sum, vector<vector<bool>>& visited){
        int n = grid.size();
        int m = grid[0].size();
        int x = 0;
        int res = 0;
        res = max(res, sum);
        visited[start_i][start_j] = true;
        for(int i = 0; i<4; i++){
            if(check(start_i + dx[i], start_j + dy[i], n, m) && grid[start_i + dx[i]][start_j + dy[i]] != 0 && !visited[start_i + dx[i]][start_j + dy[i]]){
                x = dfs(grid, start_i + dx[i], start_j + dy[i], sum + grid[start_i + dx[i]][start_j + dy[i]], visited);
                res = max(res, x);
            }
        }
        visited[start_i][start_j] = false;
        return res;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] != 0){
                    vector<vector<bool>> visited(n, vector<bool>(m, false));
                    int sum = dfs(grid, i, j, grid[i][j], visited);
                    res = max(res , sum);
                }
            }
        }
        return res;
    }
};