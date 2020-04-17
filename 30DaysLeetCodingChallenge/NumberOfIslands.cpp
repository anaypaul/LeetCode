class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    bool check(int i, int j, int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int n = grid.size();
        if(n == 0){
            return res;
        }
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1' && vis[i][j] == false){
                    res++;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    vis[i][j] = true;
                    while(!q.empty()){
                        int x = q.size();
                        for(int k = 0; k<x; k++){
                            auto curr = q.front();
                            q.pop();
                            for(int l=0; l<4; l++){
                                int ni = curr.first + dx[l];
                                int nj = curr.second + dy[l];
                                if(check(ni, nj, n, m) && grid[ni][nj] == '1' && !vis[ni][nj]){
                                    q.push(make_pair(ni, nj));
                                    vis[ni][nj] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};