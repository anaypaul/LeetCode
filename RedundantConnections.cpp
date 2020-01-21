class DSU{
public:
    int n;
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        n = n;
        vector<int> temp(n, 1);
        size = temp;
        vector<int> temp_parent(n);
        parent = temp_parent;
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
    }
    int root(int i){
        while(parent[i] != i){
            i = parent[parent[i]];
        }
        return i;
    }
    int find(int x, int y){
        if(root(x) == root(y)){
            return true;
        }
        return false;
    }
    bool weighted_merge(int x, int y){
        int rootx = root(x);
        int rooty = root(y);
        if(rootx == rooty){
            return false;
        }
        if(size[rootx] < size[rooty]){
            parent[rootx] = parent[rooty];
            size[rooty] += size[rootx];
            size[rootx] = 0;
        }else{
            parent[rooty] = parent[rootx];
            size[rootx] += size[rooty];
            size[rooty] = 0;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU * obj = new DSU(n + 1);
        for(auto e : edges){
            if(obj->weighted_merge(e[0], e[1]) == false){
                return e;
            }
        }
        return {0,0};        
    }
};