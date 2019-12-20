class Solution {
public:
    void plant(int curr, vector<vector<int>>& graph, vector<int>& res){
        for(int type = 1; type<=4; type++){
            bool flag = true;
            for(int n : graph[curr]){
                if(res[n] != -1 && res[n] == type){
                    flag = false;
                }
            }
            if(flag){
                res[curr] = type;
                return ;
            }
        }
    }
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int> res(N+1,-1);
        vector<vector<int>> graph(N+1);
        for(int i = 0; i<paths.size(); i++){
            auto to = paths[i][0];
            auto from = paths[i][1];
            graph[to].push_back(from);
            graph[from].push_back(to);
        }
        for(int i = 1; i<= N; i++){
            plant(i, graph, res);
        }
        vector<int> ans(res.begin()+1, res.end());
        return ans;
    }
};