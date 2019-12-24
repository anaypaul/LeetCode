class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    bool check(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int getDistance(vector<int> v1, vector<int> v2){
        return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]);
    }
    int maxDistance(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int res = INT_MIN;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m, false));
        bool hasWater = false;
        bool hasLand = false;
        queue<pair<pair<int,int>, int>> q;
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    q.push(make_pair(make_pair(i,j), 0));
                    vis[i][j] = true;
                    hasLand = true;
                }else{
                    hasWater = true;
                }
            }
        }
        if((hasLand && !hasWater) || (!hasLand && hasWater)){
            return -1;
        }
        while(!q.empty()){
            int x = q.size();
            for(int i = 0; i<x; i++){
                auto curr = q.front();
                q.pop();
                res = max(res, curr.second);
                for(int idx = 0; idx<4; idx++){
                    int nexti = curr.first.first + dx[idx];
                    int nextj = curr.first.second + dy[idx];
                    if(check(nexti, nextj, n, m) && !vis[nexti][nextj]){
                        q.push(make_pair(make_pair(nexti, nextj), curr.second+1));
                        vis[nexti][nextj] = true;
                    }
                }
            }
        }
        return res;
        
    }
};