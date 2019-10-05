class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> graph;
        for(int i = 0;i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        int res = 0;
        for(int i = 0; i<visited.size(); i++){
            if(visited[i] == false){
                res++;
                int start_node = i;
                //apply bfs 
                queue<int> q;
                q.push(start_node);
                visited[start_node] = true;
                while(!q.empty()){
                    int x= q.size();
                    for(int j = 0; j<x; j++){
                        int curr = q.front();
                        for(auto each : graph[curr]){
                            if(visited[each] == false){
                                q.push(each);
                                visited[each] = true;
                            }
                        }
                        q.pop();
                    }
                }
            }
        }
        return res;
    }
};