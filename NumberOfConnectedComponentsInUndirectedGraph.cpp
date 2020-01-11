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

// Approach 2 : using disjoint set
class DSU{
    public: 
    int n;
    vector<int> arr;
    vector<int> size;
    DSU(int n){
        n = n;
        vector<int> temp(n, 1);
        size = temp;
        vector<int> temp_arr(n);
        arr = temp_arr;
        for(int i = 0; i<n; i++){
            arr[i] = i;
        }
    }
    int root(int i){
        while(arr[i] != i){
            i = arr[arr[i]];
        }
        return i;
    }
    bool find(int x, int y){
        if(root(x) == root(y)){
            return true;
        }
        return false;
    }
    void weighted_union(int x, int y){
        int rootx = root(x);
        int rooty = root(y);
        if(rootx == rooty){
            return ;
        }
        if(size[rootx] < size[rooty]){
            arr[rootx] = arr[rooty];
            size[rooty] += size[rootx];
            size[rootx] = 0;
        }else{
            arr[rooty] = arr[rootx];
            size[rootx] += size[rooty];
            size[rooty] = 0;
        }
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        DSU * obj = new DSU(n);
        for(auto each : edges){
            obj->weighted_union(each[0], each[1]);
        }
        unordered_set<int> s;
        for(int i = 0; i<n; i++){
            s.insert(obj->root(i));
        }
        return s.size();
        
    }
};