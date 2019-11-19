
class Solution {
public:
    void fastIO(){
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        fastIO();
        vector<vector<int>> graph(n, vector<int>(0));
        vector<int> indegree(n, 0);
        for(auto x : pre){
            graph[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            res.push_back(t);
           for(auto next : graph[t]){
               indegree[next]--;
               if(indegree[next] == 0){
                   q.push(next);
               }
           } 
        }
        return res.size() == n;
    }
};