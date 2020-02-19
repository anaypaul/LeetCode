class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        if(n == 0){
            return {{}};
        }
        int m = mat[0].size();
        
        vector<vector<int>> res(n, vector<int>(m));
        
        for(int i = n-1; i>=0 ; i--){
            vector<int> temp;
            int starti = i;
            int startj = 0;
            while(starti < n && startj < m){
                temp.push_back(mat[starti][startj]);
                starti++;
                startj++;
            }
            sort(temp.begin(), temp.end());
            starti = i;
            startj = 0;
            int idx = 0;
            while(starti < n && startj < m){
                res[starti][startj] = temp[idx++];
                starti++;
                startj++;
            }
        }
        
        for(int j = 1; j<m; j++){
            int starti = 0;
            int startj = j;
            vector<int> temp;
            while(starti< n && startj < m){
                temp.push_back(mat[starti][startj]);
                starti++;
                startj++;
            }
            sort(begin(temp), end(temp));
            int idx = 0;
            starti = 0;
            startj = j;
            while(starti < n && startj < m){
                res[starti][startj] = temp[idx++];
                starti++;
                startj++;
            }
        }
        return res;
    }
};