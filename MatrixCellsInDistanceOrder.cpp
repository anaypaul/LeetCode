// Approach 1: brute force
class Solution {
public:
    int distance(int i, int j, int x, int y){
        return abs(x-i) + abs(y-j);
    }
    
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res; 
        unordered_map<int , vector<vector<int>>> um; 
        for(int i = 0; i<R; i++){
            for(int j = 0; j<C; j++){
                int dist = distance(i,j, r0,c0);
                um[dist].push_back({i,j});
            }
        }
        for(int i =0 ; i<201; i++){
            if(um.find(i) != um.end()){
                for(auto x: um[i]){
                    res.push_back(x);
                }
            }
        }
        return res;
    }
};
// approach 2
//  using bfs
class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    bool check(int i , int j, int n, int m ){
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        int n = R;
        int m = C;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        vis[r0][c0] = true;
        q.push(make_pair(r0, c0));
        res.push_back({r0, c0});
        while(!q.empty()){
            int x = q.size();
            for(int i = 0; i<x; i++){
                auto t = q.front();
                for(int idx = 0; idx<4; idx++){
                    if(check(t.first+dx[idx], t.second+dy[idx], n, m) && vis[t.first+dx[idx]][t.second+dy[idx]] == false){
                        res.push_back({t.first+dx[idx], t.second + dy[idx]});
                        vis[t.first+dx[idx]][t.second+dy[idx]] = true;
                        q.push(make_pair(t.first+dx[idx], t.second + dy[idx]));
                    }
                }
                q.pop();
            }
        }
        return res;
    }
};
