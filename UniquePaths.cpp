// TIme Complexity : O(n*m)
//Space Complexity : O(n*m)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<long long int>> dp(n, vector<long long int>(m, 1));
        for(int i = 1; i<n; i++){
            for(int j = 1; j<m;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};

//Space optimization
// Space : O(2*n) ~ O(n) linear space
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(m, 1);
        vector<int> curr(m, 1);
        for(int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                curr[j] = prev[j] + curr[j-1];
            }
            swap(curr, prev);
        }
        return prev[m-1];
    }
};

// Space Optimization 
// Single linear array used to store the count
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> curr(m, 1);
        for(int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                curr[j] += curr[j-1];
            }
        }
        return curr[m-1];
    }
};