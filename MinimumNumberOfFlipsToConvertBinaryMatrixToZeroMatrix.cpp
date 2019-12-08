class Solution {
public:
    string serialize(vector<vector<int>> mat){
        string res = "";
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                res += to_string(mat[i][j]) + "#";
            }
        }
        return res;
    }
    bool isZeroMat(vector<vector<int>> mat){
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                if(mat[i][j] == 1){
                    return false;
                }
            }
        }
        return true;
    }
    void addToQueue(vector<vector<int>>& mat, unordered_map<string, bool>& visited, queue<vector<vector<int>>>& q){
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                auto temp = mat;
                temp[i][j] = !temp[i][j];
                if(i+1 < n){
                    temp[i+1][j] = !temp[i+1][j];
                }
                if(i-1 >=0){
                    temp[i-1][j] = !temp[i-1][j];
                }
                if(j+1 <m){
                    temp[i][j+1] = !temp[i][j+1];
                }
                if(j-1>=0){
                    temp[i][j-1] = !temp[i][j-1];
                }
                
                auto ss = serialize(temp);
                if(!visited[ss]){
                    visited[ss] = true;
                    q.push(temp);
                }
            }
        }
    }
    int minFlips(vector<vector<int>>& mat) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        unordered_map<string, bool> visited;
        int level = 0;
        queue<vector<vector<int>> > q;
        q.push(mat);
        while(!q.empty()){
            int x = q.size();
            for(int i = 0; i<x; i++){
                auto t = q.front();
                q.pop();
                if(isZeroMat(t)){
                    return level;
                }
                addToQueue(t, visited, q);
            }
            level++;
        }
        return -1;
    }
};