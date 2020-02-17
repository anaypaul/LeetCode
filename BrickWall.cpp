//Brute force approach
//time : O(n * (sum of width of bricks in a row))
// space : O(do)
// memory limit exceeded
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int sum = accumulate(wall[0].begin(), wall[0].end(), 0);
        bool allsinglebrick = true;
        for(int i = 0; i<wall.size(); i++){
            if(wall[i].size() != 1){
                allsinglebrick = false;
                break;
            }
        }
        if(allsinglebrick){
            cout<<"all single brick"<<endl;
            return wall.size();
        }
        int n = wall.size();
        vector<vector<int>> mat(n, vector<int>(sum, 0));
        for(int i = 0; i<n; i++){
            int brickNum = 1;
            int j = 0;
            for(auto each : wall[i]){
                int x = each;
                while(x--){
                    mat[i][j] = brickNum;
                    j++;
                }
                brickNum++;
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<sum; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        int res = INT_MAX;
        for(int gap = 0; gap<sum -1; gap++){
            int count = 0;
            for(int i = 0; i<n; i++){
                if(mat[i][gap] == mat[i][gap+1]){
                    count++;
                }
            }
            cout<<"at gap "<<gap<<" intersecting bricks : "<<count<<endl;
            res = min(res, count);
        }
        return res;
    }
};