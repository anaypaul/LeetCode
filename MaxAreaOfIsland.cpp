//Approach 1 BFS 
class Solution {
private:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
public:
    bool check(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == false){
                    int curr = 0;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    curr++;
                    vis[i][j] = true;
                    while(!q.empty()){
                        int x= q.size();
                        for(int i = 0; i<x; i++){
                            auto p = q.front();
                            for(int j = 0; j<4;j++){
                                if(check(p.first+dx[j], p.second+dy[j], n, m) && grid[p.first+dx[j]][p.second+dy[j]] == 1 && vis[p.first+dx[j]][p.second+dy[j]] == false){
                                    curr++;
                                    q.push(make_pair(p.first+dx[j], p.second+dy[j] ));
                                    vis[p.first+dx[j]][p.second+dy[j]] = true;
                                }
                            }
                        }
                        q.pop();
                    }
                    res = max(res, curr);
                }
            }
        }
        return res;
    }
};