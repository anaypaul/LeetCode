class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    bool check(int i, int j, int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int maximumMinimumPath(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        typedef pair<int, pair<int,int>> pi;
        priority_queue<pi> pq;
        pq.push({grid[0][0],{0,0}});
        int res = grid[0][0];
        vis[0][0] = true;
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            res = min(res, t.first);
            if(t.second.first == n-1 && t.second.second == m-1){
                return res;
            }
            for(int idx = 0; idx<4; idx++){
                int nexti = t.second.first + dx[idx];
                int nextj = t.second.second + dy[idx];
                if(check(nexti, nextj, n, m) && vis[nexti][nextj] == false){
                    pq.push({grid[nexti][nextj], {nexti, nextj}});
                    vis[nexti][nextj] = true;
                }
            }
        }
        
        return res;
    }
};