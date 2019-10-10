//Approach 1 using BFS
class Solution {
private:
    int dx[8] = {0,0,-1,1,1,-1,-1,1};
    int dy[8] = {-1,1,0,0,1,-1,1,-1};
public:
    bool check(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n== 1 && m==1){
            return 1;
        }
        int i = 0;
        int j = 0;
        if(grid[0][0] == 1){
            return -1;
        }
        queue<pair<pair<int,int>,int>> q;
        q.push(make_pair(make_pair(0,0), 1));
        grid[0][0] = 1;
        bool reached = false;
        while(!q.empty()){
            int x = q.size();
            for(int i = 0; i<x; i++){
                auto x = q.front();
                auto p = x.first;
                int level = x.second;
                for(int j = 0; j<8; j++){
                    if(check(p.first+dx[j], p.second+dy[j], n, m) && !grid[p.first+dx[j]][p.second+dy[j]]){
                        if(p.first+dx[j] == n-1 && p.second+dy[j] == m-1){
                            return level+1;
                        }
                        q.push(make_pair(make_pair(p.first+dx[j], p.second+dy[j]), level+1));
                        grid[p.first+dx[j]][p.second+dy[j]] = 1;
                    }
                }
            }
            q.pop();
        }
        return -1;
    }
};