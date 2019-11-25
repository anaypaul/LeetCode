class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int res = 0;
        vector<int> si;
        vector<int> sj;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m ,false));
        //checking row-wise 
        for(int i = 0; i<n; i++){
            int count = 0;
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
            if(count > 1){
                for(int j = 0; j<m; j++){
                    if(grid[i][j] == 1){
                        vis[i][j] = true;
                    }
                }
                res += count;
            }   
        }
        //checking column-wise
        for(int j = 0; j<m; j++){
            int count = 0;
            int ncount =0;
            for(int i = 0; i<n; i++){
                if(grid[i][j] == 1){
                    ncount++;
                    if(vis[i][j] == false){
                        count++;
                    }
                }
            }
            if(ncount>1){
                for(int i = 0; i<n; i++){
                    if(grid[i][j] == 1 && vis[i][j] == false){
                        vis[i][j] = true;
                    }
                }
                res += count;
            }
            
        }
        return res;
    }
};