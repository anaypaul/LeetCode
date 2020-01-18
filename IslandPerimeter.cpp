class Solution {
public:
    int getWaterEdges(vector<vector<int>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        if( (i+1<n && grid[i+1][j] == 0) || i+1==n){
            ans++;
        }
        if((i-1>=0 && grid[i-1][j] == 0) || i-1==-1){
            ans++;
        }
        if((j+1<m && grid[i][j+1] ==0)   || j+1 == m){
            ans++;
        }
        if((j-1>=0 && grid[i][j-1] == 0) || j-1 ==-1){
            ans++;
        } 
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    //got starting of the island.
                    res += getWaterEdges(grid, i, j);
                }
            }
        }
        return res;
    }
};

//Approach 2
class Solution {
public:
    bool check(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    int count(int i, int j, vector<vector<int>>& grid){
        int res = 0;
        for(int idx = 0; idx<4; idx++){
            if(check(i + dx[idx], j + dy[idx], grid.size(), grid[0].size())){
                if(grid[i+dx[idx]][j + dy[idx]] == 0){
                    res++;
                }
            }else{
                res++;
            }
        }
        return res;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        if(n==0){
            return 0;
        }
        int m = grid[0].size();
        queue<pair<int , int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    q.push(make_pair(i, j));
                    vis[i][j] = true;
                    while(!q.empty()){
                        auto curr = q.front();
                        res += count(curr.first, curr.second , grid);
                        q.pop();
                        for(int idx = 0; idx<4; idx++){
                            int nx = curr.first + dx[idx];
                            int ny = curr.second + dy[idx];
                            if(check(nx, ny, n, m) && !vis[nx][ny] && grid[nx][ny] == 1){
                                q.push(make_pair(nx, ny));
                                vis[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};