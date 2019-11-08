class Solution {
public:
    void dfs(unordered_map<int, vector<int>> g, vector<int> curr_path, vector<vector<int>>& path, int currNode, int dest, vector<bool> vis){
        if(vis[currNode] == true){
            return;
        }
        if(currNode == dest){
            curr_path.push_back(currNode);
            path.push_back(curr_path);
            return;
        }
        curr_path.push_back(currNode);
        vis[currNode] = true;
        for(int i = 0; i<g[currNode].size(); i++){
            dfs(g, curr_path, path, g[currNode][i], dest, vis);
        }
        vis[currNode] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        int n = graph.size();
        unordered_map<int, vector<int> > g;
        for(int i = 0; i<graph.size(); i++){
            for(int j = 0; j<graph[i].size(); j++){
                g[i].push_back(graph[i][j]);
            }
        }
        vector<bool> vis(n, false);
        vector<int> curr_path;
        dfs(g,curr_path, res, 0, n-1, vis);
        return res;
    }
};