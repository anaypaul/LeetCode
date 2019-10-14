class Solution {
public:
    bool check(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size() == 0){
            return;
        }    
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        int n = rooms.size();
        int m = rooms[0].size();
        int emptyroom = INT_MAX;
        queue<pair<int,int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m;j++){
                if(rooms[i][j] == 0){
                    q.push(make_pair(i, j));
                }
            }
        }
        while(!q.empty()){
            auto p = q.front();
            int level = rooms[p.first][p.second];
            for(int j = 0; j<4; j++){
                if(check(p.first+dx[j], p.second+dy[j], n,m) && rooms[p.first+dx[j]][p.second+dy[j]] == emptyroom){
                    q.push(make_pair(p.first+dx[j], p.second+dy[j]));
                    rooms[p.first+dx[j]][p.second+dy[j]] = min(level + 1, rooms[p.first+dx[j]][p.second+dy[j]]);
                }
            }
            q.pop();
        }
    }
};