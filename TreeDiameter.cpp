class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = edges.size();
        vector<int> degree(n+1, 0);
        vector<vector<int>> graph(n+1 , vector<int>());
        for(int i = 0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> vis(n+1, false);
        int start = 0;
        queue<pair<int,int>> q;
        q.push(make_pair(start, 0));
        vis[start] = true;
        int lastNode = -1;
        while(!q.empty()){
            int x = q.size();
            for(int i = 0; i<x; i++){
                auto curr = q.front();
                lastNode = curr.first;
                q.pop();
                for(auto next : graph[curr.first]){
                    if(!vis[next]){
                        q.push(make_pair(next, curr.second + 1));
                        vis[next] = true;
                    }
                }
            }
        }
        int res = INT_MIN;
        fill(vis.begin(), vis.end(), false);
        q.push(make_pair(lastNode, 0));
        vis[lastNode] = true;
        while(!q.empty()){
            int x = q.size();
            for(int i = 0; i<x; i++){
                auto curr = q.front();
                res = max(res, curr.second);
                q.pop();
                for(auto next : graph[curr.first]){
                    if(!vis[next]){
                        q.push(make_pair(next, curr.second + 1));
                        vis[next] = true;
                    }
                }
            }
        }
        return res;
    }
};