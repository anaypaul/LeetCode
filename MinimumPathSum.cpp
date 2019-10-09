//brute force approach using backtracking
class Solution {
private:
    int dx[2] = {1, 0};
    int dy[2] = {0, 1};
    int res = INT_MAX;
public:
    bool check(int i,int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int helper(vector<vector<int>> grid, int sum, int start_i, int start_j){
        int n = grid.size();
        int m = grid[0].size();
        sum += grid[start_i][start_j];
        long long int val1 = INT_MAX;
        if(check(start_i+1, start_j, n,m)){
            val1 = helper(grid, sum, start_i+1, start_j);
        }
        long long int val2 = INT_MAX;
        if(check(start_i, start_j + 1, n, m)){
            val2 = helper(grid, sum, start_i, start_j+1);
        }
        if(start_i == grid.size()-1 && start_j == grid[0].size()-1){
            res = min(res, sum);
        }
        return sum + min(val1 , val2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        helper(grid, 0, 0, 0);
        return res;
    }
};
//dynamic programming approach
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n]  = {0};
        dp[0][0] = grid[0][0];
        for(int i = 1;i<m;i++){
            dp[i][0] =  grid[i][0] + dp[i-1][0];
        }
        for(int j = 1;j<n;j++){
            dp[0][j] =  grid[0][j] + dp[0][j-1];
        }
        for(int i = 1; i<m;i++){
            for(int j = 1; j<n;j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};