class DSU{
    public:
    int n;
    vector<int> arr;
    vector<int> size;
    int cost;
    int largestSize;
    DSU(int n){
        largestSize = 1;
        n = n;
        cost = 0;
        vector<int> temp(n, 1);
        vector<int> temparr(n);
        size = temp;
        arr = temparr;
        for(int i = 0; i<n; i++){
            arr[i] = i;
        }
    }
    int root(int i){
        while(arr[i] != i){
            i = arr[i];
        }
        return i;
    }
    bool find(int u, int v){
        return root(u) == root(v);
    }
    void merge(int u, int v, int c){
        int rootu = root(u);
        int rootv = root(v);
        if(rootu == rootv){
            return;
        }
        cost += c;
        if(size[rootu] < size[rootv]){
            arr[rootu] = arr[rootv];
            size[rootv] += size[rootu];
            size[rootu] = 0;
            largestSize = max(largestSize, size[rootv]);
        }else{
            arr[rootv] = arr[rootu];
            size[rootu] += size[rootv];
            size[rootv] = 0;
            largestSize = max(largestSize, size[rootu]);
        }
    }
};

class Solution {
public:
    static bool mycmp(vector<int> v1, vector<int> v2){
        if( v1[2] < v2[2]){
            return true;
        }
        return false;
    }
    int minimumCost(int N, vector<vector<int>>& connections) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        DSU * obj = new DSU(N);
        sort(connections.begin(), connections.end(), mycmp);
        for(auto each : connections){
            if(obj->find(each[0]-1, each[1]-1)){
                continue;
            }else{
                obj->merge(each[0]-1, each[1]-1, each[2]);
            }
        }
        if(obj->largestSize == N){
            return obj->cost;
        }
        return -1;
    }
};