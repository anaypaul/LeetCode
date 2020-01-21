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
        for(int i = 0; i<arr.size(); i++){
            arr[i] = i;
        }
    }
    int root(int i){
        while(arr[i] != i){
            i = arr[arr[i]];
        }
        return i;
    }
    void weighted_union(int x , int y){
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
    bool find(int x, int y){
        if(root(x) == root(y)){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int getTriangleNumber(int i, int j ,int n, int number){
        return 4 * (i * n + j )+ number;
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        DSU * obj = new DSU(4 * n * n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] != '/'){
                    obj->weighted_union(getTriangleNumber(i, j, n, 0), getTriangleNumber(i, j, n, 2));
                    obj->weighted_union(getTriangleNumber(i, j, n, 1), getTriangleNumber(i, j, n, 3));
                } 
                if(grid[i][j] != '\\'){
                    obj->weighted_union(getTriangleNumber(i, j, n, 0), getTriangleNumber(i, j, n, 1));
                    obj->weighted_union(getTriangleNumber(i, j, n, 2), getTriangleNumber(i, j, n, 3));
                }
                
                //up
                if(i - 1 >=0){
                    obj->weighted_union(getTriangleNumber(i-1, j, n, 3), getTriangleNumber(i,j,n, 0));
                }
                //down
                if(i + 1 < n){
                    obj->weighted_union(getTriangleNumber(i+1, j, n, 0), getTriangleNumber(i, j, n, 3));
                }
                //right
                if(j + 1 < n){
                    obj->weighted_union(getTriangleNumber(i, j+1, n, 1), getTriangleNumber(i, j, n, 2));
                }
                //left
                if(j-1 >=0){
                    obj->weighted_union(getTriangleNumber(i, j-1,n, 2 ), getTriangleNumber(i, j, n, 1));
                }
            }
        }
        int res = 0;
        for(int i = 0; i<4 * n * n; i++){
            if(obj->root(i) == i){
                res++;
            }
        }
        return res;
    }
};