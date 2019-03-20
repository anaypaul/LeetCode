class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        //brute force solution
        vector<int> result;
        if(positions.empty()){
            result.push_back(0);
            return result;
        }
        int grid[m][n] = {0};
        for(int index = 0;index<positions.size();index++){
            memset(grid, 0, sizeof(grid[0][0]) * m * n);
            for(int pos = 0;pos<=index;pos++){
                grid[positions[pos].first][positions[pos].second] = 1;
            }
            
            int islands = 0;
            for(int i = 0;i<m;i++){
                for(int j = 0;j<n;j++){
                    if(grid[i][j] == 1){
                        //BFS
                        islands++;
                        queue<pair<int, int>> q;
                        q.push(make_pair(i,j));
                        grid[i][j] = 0;
                        while(!q.empty()){
                            pair<int, int> temp = q.front();
                            grid[temp.first][temp.second] = 0;
                            q.pop();
                            if(temp.first+1 < m && grid[temp.first+1][temp.second]==1){
                                q.push(make_pair(temp.first+1, temp.second));
                                grid[temp.first+1][temp.second] = 0;
                            }
                            if(temp.first-1>=0 && grid[temp.first-1][temp.second]==1){
                                q.push(make_pair(temp.first-1, temp.second));
                                grid[temp.first-1][temp.second] = 0;
                            }
                            if(temp.second+1 < n && grid[temp.first][temp.second+1] == 1){
                                q.push(make_pair(temp.first, temp.second+1));
                                grid[temp.first][temp.second + 1]= 0;
                            }
                            if(temp.second -1 >=0 && grid[temp.first][temp.second-1] == 1){
                                q.push(make_pair(temp.first, temp.second-1));
                                grid[temp.first][temp.second-1] = 0;
                            }
                        }
                    }
                }
            }
            cout<<"no of islands :"<<islands<<endl;
            result.push_back(islands);
        }
        return result;
    }
};