class Solution {
public:
    void buildGraph(vector<vector<int>>& graph, vector<vector<int>>& edges, vector<int>& degree){
        for(auto x : edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
            degree[x[0]]++;
            degree[x[1]]++;
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1){
            return {0};
        }
        if(edges.size() == 0){
            return {};
        }
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> degree(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        buildGraph(graph, edges, degree);
        vector<int> res;
        vector<bool> vis(n, false);
        vector<int> heights(n); // root node and height. 
        queue<int> q;
        for(int i = 0; i<degree.size(); i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x = q.size();
            res.clear();
            for(int i = 0; i<x; i++){
                auto t = q.front();
                q.pop();
                res.push_back(t);
                for(auto next : graph[t]){
                    degree[next] --;
                    if(degree[next]== 1){
                        q.push(next);
                    }
                }
            }
        }
        return res;
    }
};