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