class Solution {
private:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
public:
    bool check(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n== 0){
            return;
        }
        int m = board[m].size();
        if(m==0){
            return ;
        }
        vector<vector<bool>> vis(n , vector<bool>(m, false));
        queue<pair<int,int>> q;
        //check boundary for Os 
        for(int i =0; i<n ; i++){
            if(board[i][0] == 'O'){
                q.push(make_pair(i, 0));
                vis[i][0] = true;
            }
            if(board[i][m-1] == 'O'){
                q.push(make_pair(i, m-1));
                vis[i][m-1] = true;
            }
        }
        for(int j = 0; j<m; j++){
            if(board[0][j] == 'O'){
                q.push(make_pair(0, j));
                vis[0][j] = true;
            }
            if(board[n-1][j] == 'O'){
                q.push(make_pair(n-1, j));
                vis[n-1][j] = true;
            }
        }
        while(!q.empty()){
            int x = q.size();
            for(int i = 0; i<x; i++){
                auto p = q.front();
                for(int j = 0; j<4; j++){
                    if(check(p.first+dx[j], p.second+dy[j], n, m) && vis[p.first+dx[j]][p.second+dy[j]] == false && board[p.first+dx[j]][p.second+dy[j]] == 'O'){
                        q.push(make_pair(p.first+dx[j], p.second+dy[j]));
                        vis[p.first+dx[j]][p.second+dy[j]] = true;
                    }
                }
                q.pop();
            }
        }
        for(int i= 0; i<n ; i++){
            for(int j =0; j<m;j++){
                if(vis[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
    }
};