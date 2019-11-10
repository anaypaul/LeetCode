class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<int> count(3);
        for(auto it : colsum){
            count[it]++;
        }
        int v = count[2];
        int x = upper -v;
        int y = lower -v;
        if(x<0 || y<0 || x + y != count[1]){
            return {};
        }
        int n = colsum.size();
        vector<vector<int>> res(2, vector<int>(n,0));
        for(int i = 0; i<n; i++){
            if(colsum[i] == 0){
                
            }else if(colsum[i] == 2){
                res[0][i] = res[1][i] = 1;
            }else{
                if(x){
                    res[0][i] = 1;
                    res[1][i] = 0;
                    x--;
                }else {
                    res[0][i] = 0;
                    res[1][i] = 1;
                    y--;
                }
            }
        }
        return res;
    }
};