class Solution {
public:
    int getmin(int a, int b, int c){
        return min(a, min(b,c));
    }
    int countSquares(vector<vector<int>>& matrix) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int res = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 1){
                    dp[i+1][j+1] += matrix[i][j] + getmin(dp[i][j], dp[i][j+1], dp[i+1][j]);
                    res += dp[i+1][j+1];
                }
            }
        }
        return res;      
    }
};

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 1){
                    dp[i][j] = 1;
                }
            }
        }
        
        for(int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                if(dp[i][j] == 1){
                    dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j])) + 1;
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout<<dp[i][j]<<" ";
                res += dp[i][j];
            }
            cout<<endl;
        }
        return res;
    }
};