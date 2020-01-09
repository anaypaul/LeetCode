class DSU{
    public:
    int n;
    vector<int> arr;
    vector<int> size;
    DSU(int n){
        n = n;
        vector<int> temp(n, 0);
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
    void merge(int x, int y){
        int rootx = root(x);
        int rooty = root(y);
        if(rootx == rooty){
            return;
        }
        if(size[rootx] < size[rooty]){
            arr[rootx] = arr[rooty];
            size[rooty] += size[rootx];
        }else{
            arr[rooty] = arr[rootx];
            size[rootx] += size[rooty];
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = A.size();
        DSU * obj = new DSU(26);
        unordered_set<int> myset;
        for(int i = 0; i<A.size(); i++){
            obj->size[A[i]-'a'] = 1;
            myset.insert(A[i]-'a');
        }
        for(int i = 0; i<A.size(); i++){
            obj->size[B[i]-'a'] = 1;
            myset.insert(B[i]-'a');
        }
        for(int i = 0; i<26; i++){
            if(myset.find(i) == myset.end()){
                obj->arr[i] = -1;
            }
        }
        for(int i = 0; i<n; i++){
            obj->merge(A[i]-'a', B[i]-'a');
            obj->merge(A[i]-'a', A[i]-'a');
            obj->merge(B[i]-'a', B[i]-'a');
        }
        string res;
        vector<int> roots;
        for(int i = 0; i<obj->size.size(); i++){
            if(obj->size[i] > 0){
                roots.push_back(i);
            }
        }
        unordered_map<int , set<int>> m;
        for(int i = 0; i<26; i++){
            if(obj->size[i] >0){
                m[obj->root(i)].insert(i);
            }
        }
        for(int i = 0; i<S.size(); i++){
            if(obj->arr[S[i]-'a'] == -1){
                res += S[i];
                continue;
            }
            int idx = obj->root(S[i]-'a');
            auto itr = m[idx].begin();
            char c = *itr + 'a';
            res += c;
        }
        return res;
    }
};