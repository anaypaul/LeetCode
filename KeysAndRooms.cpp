class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = rooms.size();
        vector<bool> vis(n , false);
        vector<vector<int>> graph(n, vector<int>());
        for(int i = 0; i<n; i++){
            for(int j = 0; j<rooms[i].size(); j++){
                graph[i].push_back(rooms[i][j]);
            }
        }
        vis[0] = true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int x = q.size();
            for(int i = 0; i<x; i++){
                auto curr = q.front();
                q.pop();
                for(int n : graph[curr]){
                    if(!vis[n]){
                        q.push(n);
                        vis[n] = true;
                    }
                }
            }
        }
        for(int i = 0; i<vis.size(); i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
        
    }
};