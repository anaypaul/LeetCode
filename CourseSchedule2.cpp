class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = numCourses;
        vector<vector<int>> graph(n , vector<int>(0));
        vector<int> indegree(n, 0);
        for(auto x : prerequisites){
            indegree[x[0]]++;
            graph[x[1]].push_back(x[0]);
        }
        vector<int> res;
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            res.push_back(t);
            for(auto x : graph[t]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        if(res.size() == n){
            return res;
        }
        return {};
    }
};