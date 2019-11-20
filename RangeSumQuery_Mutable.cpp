class NumArray {
public:
    vector<int> v;
    vector<int> tree;
    NumArray(vector<int>& nums) {
        if(nums.size() == 0){
            return;
        }
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        for(auto x : nums){
            v.push_back(x);
        }
        int size = v.size();
        int x = 1;
        for(x = 1; x<size; x = x* 2);
        vector<int> temp_tree(2*x-1);
        tree = temp_tree;
        build(0, 0, v.size()-1);
    }
    void build(int node, int start, int end){
        if(start == end){
            tree[node] = v[start];
            return;
        }
        int mid = (start + end)/2;
        build(2*node+1, start , mid);
        build(2*node+2, mid + 1, end);
        tree[node] = tree[2*node + 1] + tree[2*node + 2];
    }
    void myupdate(int node , int start, int end, int idx, int val){
        if(start == end){
            tree[node] = val;
        }else{
            int mid = (start + end)/2;
            if(start<= idx && idx<=mid){
                myupdate(2*node + 1, start, mid, idx, val);
            }else{
                myupdate(2*node + 2 , mid +1 , end, idx, val);
            }
            tree[node] = tree[2*node + 1] + tree[2* node + 2];
        }
        
    }
    void update(int i, int val) {
        myupdate(0, 0, v.size()-1, i, val);
    }
    int query(int node, int start, int end, int L, int R){
        if(end < L || start > R){
            return 0;
        }
        if(L<=start && end<=R){
            return tree[node];
        }
        int mid = (start + end)/2;
        int left = query(2*node + 1, start, mid, L, R);
        int right = query(2*node +2, mid+1, end, L,R);
        return left + right;
    }
    int sumRange(int i, int j) {
        return query(0, 0, v.size()-1, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */