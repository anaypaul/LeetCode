class Solution {
public:
    bool check(int i, int j, int n, int m ){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> res;
        int i = r0;
        int j = c0;
        int len = 2;
        int items = R*C;
        int direction = 0;
        while(items > 0){
            for(int iter = 0; iter<2; iter++){
                int x = len-1;
                while(x>0 && items>0){
                    if(check(i, j, R, C)){
                        res.push_back({i,j});
                        items--;                    
                    }
                    i = i + dx[direction];
                    j = j + dy[direction];
                    x--;
                }
                direction = (direction+1)%4;
                x = len-1;
                while(x>0 && items>0){
                    if(check(i,j,R, C)){
                        items--;
                        res.push_back({i,j});
                    }
                    i = i + dx[direction];
                    j = j + dy[direction];
                    x--;
                }
                direction = (direction+1)%4;
                len++;
            }
        }
        return res;
    }
};