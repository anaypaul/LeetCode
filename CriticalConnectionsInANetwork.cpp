class Solution {
public:
    void dfs(int u, int parent, vector<int>& ids, vector<bool>& visited, vector<int>& low, vector<vector<int>>& graph, vector<vector<int>>& result) {
        visited[u] = true;
        int id = ids[parent] + 1;
        low[u] = id;
        ids[u] = id;
        for (int n : graph[u]) {
            if (n == parent) continue;
            if (!visited[n]) {
                dfs(n, u, ids, visited, low, graph, result);
                low[u] = min(low[u], low[n]);
                if (ids[u] < low[n]) {
                    result.push_back({u, n});
                }
            } else {
                low[u] = min(low[u], ids[n]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //construct a graph using the given connections
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> graph(n, vector<int>(0));
        for(auto x : connections ){
            auto to = x[0];
            auto from = x[1];
            graph[to].push_back(from);
            graph[from].push_back(to);
        }
        vector<vector<int>> result;
        vector<bool> visited(n, false);
        vector<int> low(n , -1);
        vector<int> ids(n , 0);
        
        for(int i = 0; i<n ; i++){
            if(!visited[i]){
                dfs(i, i, ids, visited, low, graph, result);
            }
        }
        return result;
    }
};