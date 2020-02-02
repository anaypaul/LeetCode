class Solution {
public:
    int dp[50][50][50];
    vector<vector<int>> grid;
    int helper(int r1, int c1, int c2, int n){
        int r2 = r1 + c1 - c2;
        if(r1>= n || c1>=n || r2>=n || c2>=n || grid[r1][c1] == -1 || grid[r2][c2] == -1){
            return INT_MIN;
        }
        if(dp[r1][c1][c2] != -1){
            return dp[r1][c1][c2];
        }
        if(r1 == n-1 && c1 == n-1){
            return grid[r1][c1];
        }
        
        int ans = grid[r1][c1];
        if(r1 != r2){
            ans += grid[r2][c2];
        }
        int temp = max(helper(r1, c1+1, c2+1, n), helper(r1+1, c1, c2+1, n));
        temp = max(temp, helper(r1, c1+1, c2, n));
        temp = max(temp, helper(r1+1, c1, c2, n));
        ans += temp;
        dp[r1][c1][c2] = ans;
        return ans;
    }
    int cherryPickup(vector<vector<int>>& g) {
        int n = g.size();
        if(n == 0){
            return 0;
        }
        grid = g;
        memset(dp, -1, sizeof(dp));
        return max(0, helper(0,0,0,n));
    }
};