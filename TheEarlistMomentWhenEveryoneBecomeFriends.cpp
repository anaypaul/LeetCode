class DSU{
    public:
    int n;
    vector<int> arr;
    vector<int> size;
    int largestSet;
    DSU(int n){
        largestSet = 1;
        n = n;
        vector<int> temp(n, 1);
        size = temp;
        vector<int> temparr(n);
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
    bool find(int x, int y){
        if(root(x) == root(y)){
            return true;
        }
        return false;
    }
    void weight_union(int x, int y){
        int rootx = root(x);
        int rooty = root(y);
        if(find(x, y)){
            return ;
        }
        if(size[rootx] < size[rooty]){
            arr[rootx] = arr[rooty];
            size[rooty] += size[rootx];
            size[rootx] = 0;
            largestSet = max(largestSet, size[rooty]);
        }else{
            arr[rooty] = arr[rootx];
            size[rootx] += size[rooty];
            size[rooty] = 0;
            largestSet = max(largestSet, size[rootx]);
        }
    }
    bool allAreFriends(){
        return largestSet == n;
    }
};
class Solution {
public:
    static bool mycmp(vector<int>& v1, vector<int>& v2){
        if(v1[0] < v2[0]){
            return true;
        }
        return false;
    }
    int earliestAcq(vector<vector<int>>& logs, int N) {
        DSU *obj = new DSU(N);
        sort(logs.begin(), logs.end(), mycmp);
        for(auto each : logs){
            if(obj->allAreFriends()){
                return each[0];
            }else{
                obj->weight_union(each[1], each[2]);
                if(obj->largestSet == N){
                    return each[0];
                }
            }
        }
        return -1;
    }
};