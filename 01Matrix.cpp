
class Solution {
private:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
public:
    bool check(int i, int j, int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        queue<pair<int,int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m;j++){
                if(matrix[i][j] == 0){
                    res[i][j] = 0;
                    q.push(make_pair(i,j));
                }
            }
        }
        while(!q.empty()){
            int x = q.size();
            for(int i = 0; i<x;i++){
                auto p = q.front();
                for(int j = 0; j<4; j++){
                    if(check(p.first+dx[j], p.second+dy[j], n, m )){
                        if(res[p.first+dx[j]][p.second+dy[j]] > res[p.first][p.second] + 1){
                            res[p.first+dx[j]][p.second+dy[j]] = res[p.first][p.second] +1;
                            q.push(make_pair(p.first+dx[j], p.second+dy[j]));
                        }
                    }
                }
                q.pop();
            }
        }
        return res;
    }
};