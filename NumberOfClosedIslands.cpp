#define mk make_pair
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
class Solution {
public:
    bool isborder(int i, int j, int n, int m){
        return i == 0 || i== n-1 || j == 0 || j == m-1;
    }
    bool check(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int closedIsland(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int res = 0;
        int n = grid.size();
        if(n == 0){
            return 0;
        }
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    bool isClosed = true;
                    queue<pair<int,int>> q;
                    vis[i][j] = true;
                    q.push(mk(i, j));
                    while(!q.empty()){
                        int x = q.size();
                        for(int k = 0; k<x; k++){
                            auto t = q.front();
                            // cout<<t.first<<" "<<t.second<<endl;
                            if(isborder(t.first, t.second, n, m ) && isClosed){
                                isClosed = false;
                            }
                            for(int idx = 0; idx<4; idx++){
                                int nexti = t.first + dx[idx];
                                int nextj = t.second + dy[idx];
                                if(check(nexti, nextj, n, m ) &&!vis[nexti][nextj] && grid[nexti][nextj] == 0){
                                    q.push(mk(nexti, nextj));
                                    vis[nexti][nextj] = true;
                                }
                            }
                            q.pop();
                        }
                    }
                    if(isClosed == true){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};