class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    bool check(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis,int hash, vector<int>& sign){
        if(check(i, j, grid.size(), grid[0].size()) == false){
            return ;
        }
        if(vis[i][j] == true){
            return;
        }
        if(grid[i][j] == 0){
            return ;
        }
        vis[i][j] = true;
        sign.push_back(hash);
        for(int idx = 0; idx< 4; idx++){
            dfs(i + dx[idx], j + dy[idx], grid, vis,idx + 1, sign );
        }
        sign.push_back(0);
    }
    string vec2string(vector<int> arr){
        string res = "";
        for(auto x : arr){
            res += to_string(x) + "#";
        }
        return res;
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0){
            return 0;
        }
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        unordered_set<string> s;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    vector<int> sign(1,0);
                    dfs(i, j, grid, vis,0,  sign);
                    string signature = vec2string(sign);
                    s.insert(signature);
                }
            }
        }
        return s.size();
    }
};