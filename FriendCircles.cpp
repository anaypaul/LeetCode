//Approach 1 by constructing an explicit graph 
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int circles = 0;
        vector<bool> visited(M.size(), false);
        unordered_map<int, unordered_set<int>> graph;
        for(int i = 0;i<M.size(); i++){
            for(int j = 0; j<M[i].size(); j++){
                if(M[i][j] == 1){
                    graph[i].insert(j);
                    graph[j].insert(i);
                }
            }
        }
        for(int i = 0; i<visited.size(); i++){
            if(visited[i] == false){
                circles++;
                int start_node = i;
                queue<int> q;
                q.push(start_node);
                visited[start_node] = true;
                while(!q.empty()){
                    int x= q.size();
                    for(int j = 0;j<x; j++){
                        int curr = q.front();
                        for(int each : graph[curr]){
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
        return circles;
    }
};


//Approach 2 without making an explicity graph and treating the matrix as implicit graph.
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int circles = 0;
        vector<bool> visited(M.size(), false);
        for(int i = 0; i<visited.size(); i++){
            if(visited[i] == false){
                circles++;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while(!q.empty()){
                    int x = q.size();
                    while(x--){
                        int curr = q.front();
                        for(int j = 0 ; j<M[curr].size(); j++){
                            if(M[curr][j] == 1 && visited[j] == false){
                                q.push(j);
                                visited[j] = true;
                            }
                        }
                        q.pop();
                    }
                }
            }
        }
        return circles;
    }
};