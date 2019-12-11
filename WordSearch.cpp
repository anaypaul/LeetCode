class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    int n;
    int m;
    bool check(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    bool dfs(int i,int j, vector<vector<char>> & board, string word,  int currIndex){
        if(currIndex == word.size()){
            return true;
        }
        if(!check(i, j, n, m)){
            return false;
        }
        char temp = word[currIndex];
        if(board[i][j] != temp){
            return false;
        }
        board[i][j] = '#';
        if(dfs(i+ dx[0], j + dy[0], board, word, currIndex + 1)){
            return true;
        }
        if(dfs(i+ dx[1], j + dy[1], board, word, currIndex + 1)){
            return true;
        }
        if(dfs(i+ dx[2], j + dy[2], board, word, currIndex + 1)){
            return true;
        }
        if(dfs(i+ dx[3], j + dy[3], board, word, currIndex + 1)){
            return true;
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m, false));
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(dfs(i, j, board, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};