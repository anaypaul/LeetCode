class Solution {
public:
    bool check(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0){
            return 0;
        }
        int m = grid[0].size();
        if(n==1 && m == 1 && grid[0][0] == 1){
            return 0;
        }else if(n==1 && m==1 && grid[0][0] == 0){
            return 1;
        }
        if(grid[0][0] == 1){
            return 0;
        }
        vector<vector<long long int>> dp(n , vector<long long int>(m , 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m;j++){
                dp[i][j]  = grid[i][j];
            }
        }
        dp[0][0] = 1;
        for(int i = 1; i<n; i++){
            dp[i][0] = dp[i][0] == 0 && dp[i-1][0]==1 ? 1 : 0;
        }
        for(int j = 1; j<m; j++){
            dp[0][j] = dp[0][j] == 0 && dp[0][j-1]==1 ? 1 : 0;
        }
        
        for(int i = 1; i<n;i++){
            for(int j = 1; j<m;j++){
                if(dp[i][j] ==0 ){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[n-1][m-1];
        
     }
};