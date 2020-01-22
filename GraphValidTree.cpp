class DSU{
    public:
    int n;
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        n = n;
        vector<int> p(n);
        parent = p;
        for(int i = 0; i<p.size(); i++){
            parent[i] = i;
        }
        vector<int> sizet(n, 1);
        size = sizet;
    }
    int root(int i){
        while(parent[i] != i){
            i = parent[parent[i]];
        }
        return i;
    }
    bool find(int x, int y){
        if(root(x) == root(y)){
            return true;
        }
        return false;
    }
    bool weighted_union(int x, int y){
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
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU * obj = new DSU(n);
        for(int i = 0; i<edges.size(); i++){
            if(obj->weighted_union(edges[i][0], edges[i][1])){
                continue;
            }else{
                return false;
            }
        }
        int root = 0;
        for(int i = 0; i<n; i++){
            if(i == obj->root(i)){
                root++;
            }
            if(root>1){
                return false;
            }
        }
        return true;
    }
};