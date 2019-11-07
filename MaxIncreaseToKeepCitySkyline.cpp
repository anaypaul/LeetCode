class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> leftright (n, 0);
        for(int i = 0; i<n; i++){
            leftright[i] = *max_element(grid[i].begin(), grid[i].end());
        }
        
        vector<int> topbottom(m , 0);
        for(int j = 0; j<m; j++){
            int maxVal = INT_MIN;
            for(int i = 0; i<n; i++){
                if(grid[i][j] > maxVal){
                    maxVal = grid[i][j];
                }
            }
            topbottom[j] = maxVal;
        }
        int res = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0;j<m; j++){
                res = res + min(leftright[i], topbottom[j]) - grid[i][j];   
            }
        }
        return res;
    }
};