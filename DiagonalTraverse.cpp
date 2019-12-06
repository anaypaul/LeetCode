class Solution {
public:
    bool check(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> res;
        int n = matrix.size();
        if(n ==0 ){
            return {};
        }
        int m = matrix[0].size();
        int iters = n + m -1;
        int starti = 0;
        int startj = 0;
        int i = -1, j = -1;
        bool flag = false;
        while(iters >= 0){
            iters--;
            i = starti;
            j = startj;
            vector<int> temp;
            while(check(i,j,n,m)){
                temp.push_back(matrix[i][j]);
                i++;
                j--;
            }
            if(temp.size()!= 0){
                res.push_back(temp);
            }
            if(startj<m && !flag){
                startj++;
            }else{
                if(!flag){
                    startj--;
                }
                flag = true;
                starti++;
            }
        }
        vector<int> ans;
        for(int i = 0; i<res.size(); i++){
            if(i % 2 == 0){
                for(int j = res[i].size()-1; j>=0; j--){
                    ans.push_back(res[i][j]);
                }
            }else{
                for(int j = 0; j<res[i].size(); j++){
                    ans.push_back(res[i][j]);
                }
            }
        }
        return ans;
    }
};