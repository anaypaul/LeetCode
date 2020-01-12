class DSU{
    public:
    int n;
    vector<int> arr;
    vector<int> size;
    int extra;
    DSU(int n){
        extra = 0;
        n = n;
        vector<int> temp(n, 1);
        size = temp;
        vector<int> temp_arr(n);
        arr = temp_arr;
        for(int i = 0; i< n; i++){
            arr[i] = i;
        }
    }
    int root(int i){
        while(arr[i] != i){
            i = arr[arr[i]];
        }
        return i;
    }
    void merge(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry){
            extra++;
            return;
        }
        if(size[rx] < size[ry]){
            arr[rx] = arr[ry];
            size[ry] += size[rx];
            size[rx] = 0;
        }else{
            arr[ry] = arr[rx];
            size[rx] += size[ry];
            size[ry] = 0;
        }
    };
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU * obj = new DSU(n);
        for(auto each : connections){
            obj->merge(each[0], each[1]);
        }
        int comp = 0;
        unordered_set<int> s;
        for(int i = 0; i<n; i++){
            int r = obj->root(i);
            s.insert(r);
        }
        int x= s.size();
        if( x-1 > obj->extra ){
            return -1;
        }
        return x-1;
        
    }
};