class Solution {
public:
    bool check(vector<vector<int>> mat){
        
        bool res = true;
        unordered_set<int> us;
        //check distinct digits or not
        for(int i = 0;i<mat.size(); i++){
            for(int j = 0;j<mat[0].size(); j++){
                if(!(mat[i][j]>=1 && mat[i][j]<=9)){
                    return false;
                }
                if(us.find(mat[i][j]) !=us.end()){
                    return false;
                }
                us.insert(mat[i][j]);
            }
        }
        //row - wise 
        int val = accumulate(mat[0].begin(), mat[0].end(), 0);
        for(int i = 1; i<3;i++){
            if(val != accumulate(mat[i].begin(), mat[i].end(), 0)){
                return false;
            }
        }
        //col 
        for(int j = 0; j<mat[0].size(); j++){
            int sum = 0;
            for(int i = 0; i<mat.size(); i++){
                sum += mat[i][j];
            }
            if(val != sum ){
                return false;
            }
        }
        if(mat[0][0] + mat[2][2] != mat[0][2] + mat[2][0]){
            return false;
        }
        return res;
        
    }
    bool printmat(vector<vector<int>> grid, int i, int j){
        vector<vector<int>> temp(3, vector<int>(3, 0));
        int ii = 0;
        int jj = 0;
        for(int ix = i; ix<i+3; ix++){
            for(int jy = j; jy<j+3; jy++){
                temp[ii][jj] = grid[ix][jy];
                jj++;
            }
            ii++;
            jj=0;
            cout<<endl;
        }
        if(check(temp)){
            return true;
        }
        return false;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;
        if(grid.size()<3 || grid[0].size()<3){
            return res;
        }
        for(int i= 0; i<grid.size()-2; i++){
            for(int j = 0; j<grid[i].size()-2; j++){
                if(printmat(grid, i, j)){
                    res++;
                }
            }
        }
        return res;
    }
};