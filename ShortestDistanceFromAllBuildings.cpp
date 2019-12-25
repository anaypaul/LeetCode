class Solution {
public:
    bool check(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    int shortestDistance(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> reach(n, vector<int>(m, 0));
        int bCount= 0;
        vector<vector<int>> start;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    bCount++;
                    dist[i][j] = INT_MAX;
                    start.push_back({i,j});
                }else if(grid[i][j] == 2){
                    dist[i][j] = INT_MAX;
                }
            }
        }
        
        for(auto each : start){
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            queue<pair<pair<int,int>, int>> q;
            q.push(make_pair(make_pair(each[0], each[1]), 0));
            while(!q.empty()){
                int x = q.size();
                for(int i = 0; i<x; i++){
                    auto curr = q.front();
                    q.pop();
                    dist[curr.first.first][curr.first.second] += curr.second;
                    for(int idx = 0; idx<4; idx++){
                        int nexti = curr.first.first + dx[idx];
                        int nextj = curr.first.second + dy[idx];
                        if(check(nexti, nextj, n, m ) && grid[nexti][nextj] == 0 && vis[nexti][nextj] == false){
                            reach[nexti][nextj]++;
                            vis[nexti][nextj] = true;
                            q.push(make_pair(make_pair(nexti, nextj), curr.second + 1));
                        }
                    }
                }
            }
        }
        
        int res = INT_MAX;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(reach[i][j] == bCount && dist[i][j] != INT_MAX){
                    res = min(res, dist[i][j]);
                }
            }
        }
        if(res == INT_MAX){
            return -1;
        }
        return res;
    }
};