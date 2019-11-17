class Solution {
public:
    pair<int,int> linearTo2D(int index, int n, int m){
        pair<int,int> p = make_pair(index/m, index%m);
        return p;
    }
    int toLinear(int i, int j, int n, int m){
        return i*m + j;
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        k = k % (n*m);
        if(k==0){
            return grid;
        }
        vector<vector<int>> res(n, vector<int>(m)); 
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int linear_index = (toLinear(i,j,n,m) + k) % (n*m);
                pair<int,int> p = linearTo2D(linear_index , n, m);
                res[p.first][p.second] = grid[i][j];
            }
        }
        return res;
    }
};