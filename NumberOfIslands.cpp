class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0){
            return 0;
        }
        if(grid.empty()){
            return 0;
        }
        int numberOfIslands = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0; i<rows;i++){
            for(int j = 0; j<cols;j++){
                if(grid[i][j] == '1'){
                    numberOfIslands++;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i,j));
                    grid[i][j] = '0';
                    while(!q.empty()){
                        pair<int,int> temp = q.front();
                        grid[temp.first][temp.second] = '0';
                        q.pop();
                        if(temp.first+1< rows && grid[temp.first+1][temp.second]=='1'){
                            grid[temp.first+1][temp.second] = '0';
                            q.push(make_pair(temp.first+1, temp.second));
                        }
                        if(temp.first-1>=0 && grid[temp.first-1][temp.second] == '1'){
                            grid[temp.first-1][temp.second] = '0';
                            q.push(make_pair(temp.first-1, temp.second));
                        }
                        if(temp.second+1 < cols && grid[temp.first][temp.second+1] == '1'){
                            grid[temp.first][temp.second+1] = '0';
                            q.push(make_pair(temp.first, temp.second + 1));
                        }
                        if(temp.second-1 >= 0 && grid[temp.first][temp.second-1] == '1'){
                            grid[temp.first][temp.second-1] = '0';
                            q.push(make_pair(temp.first, temp.second -1));
                        }
                    }
                }
            }
        }
        return numberOfIslands;
    }
};