class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int n = M.size();
        int m = M[0].size();
        int dx[9] = {-1,-1,-1,0,0,0,1,1,1};
        int dy[9] = {-1,0,1,-1,0,1,-1,0,1};
        vector<vector<int>> res(M.size(), vector<int>(M[0].size(), 0));
        for(int i = 0;i<M.size();i++){
            for(int j = 0;j<M[0].size();j++){
                int sum = 0;
                int count = 0;
                for(int idx = 0;idx<9;idx++){
                    int index_x = i + dx[idx];
                    int index_y = j + dy[idx];
                    if((index_x>=0 &&index_x<n) && (index_y>=0 && index_y<m)){
                        sum += M[index_x][index_y];
                        count++;
                    }
                }
                res[i][j] = sum/count;
            }
        }
        return res;
    }
};