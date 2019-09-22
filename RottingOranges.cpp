class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n== 0){
            return 0;
        }
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n , vector<bool>(m , false));
        queue<pair<int, int>> q;
        queue<int> level;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    visited[i][j] = true;
                    q.push(make_pair(i,j));
                    level.push(0);
                }
            }
        }
        int answer = 0;
        while(!q.empty()){
            pair<int, int> t = q.front();
            q.pop();
            int l = level.front();
            level.pop();
            answer = l;
            if(t.first+1<n && visited[t.first+1][t.second]==false && grid[t.first+1][t.second] == 1){
                q.push(make_pair(t.first+ 1, t.second));
                level.push(l+1);
                visited[t.first+1][t.second] = true;
            }
            if(t.first-1>=0 && visited[t.first-1][t.second] == false && grid[t.first-1][t.second] == 1){
                q.push(make_pair(t.first-1, t.second));
                level.push(l+1);
                visited[t.first - 1][t.second] = true;
            }
            if(t.second -1 >= 0 && visited[t.first][t.second-1]== false && grid[t.first][t.second-1] == 1){
                q.push(make_pair(t.first, t.second-1));
                level.push(l+1);
                visited[t.first][t.second -1] = true;
            }
            if(t.second + 1<m && visited[t.first][t.second + 1]== false && grid[t.first][t.second + 1]== 1){
                q.push(make_pair(t.first, t.second + 1));
                level.push(l+1);
                visited[t.first][t.second + 1] = true;
            }
        }
        for( int i = 0 ; i < n ;i++ ){
            for( int j = 0 ; j < m ; j++ ){
                if((visited[i][j]==false)&&(grid[i][j]==1)){
                    return -1;
                }
            }
        }
        return answer;
        
    }
};