class DSU{
    public:
    int n;
    vector<int> arr;
    vector<int> size;
    DSU(int n){
        n = n;
        vector<int> temp(n,1);
        size = temp;
        vector<int> temp_arr(n);
        arr = temp_arr;
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
        if(root(u) == root(v)){
            return true;
        }
        return false;
    }
    void weighted_union(int u, int v){
        int rootu = root(u);
        int rootv = root(v);
        if(rootu == rootv){
            return ;
        }
        if(size[rootu] < size[rootv]){
            arr[rootu] = arr[rootv];
            size[rootv] += size[rootu];
        }else{
            arr[rootv] = arr[rootu];
            size[rootu] += size[rootv];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = accounts.size();
        DSU * obj = new DSU(n);
        map<string , int> email2person;
        for(int i = 0; i<accounts.size(); i++){
            for(int j = 1; j<accounts[i].size(); j++){
                string email = accounts[i][j];
                if(email2person.find(email) != email2person.end()){
                    int u = email2person[email];
                    obj->weighted_union(i, u);
                }else{
                    email2person[email] = i;
                }
            }
        }
        
        map<int , set<string>> person2email;
        for(auto x : email2person){
            string email = x.first;
            int id = obj->root(x.second);
            person2email[id].insert(email);
        }
        vector<vector<string>> res;
        for(auto x : person2email){
            vector<string> temp;
            int idx = x.first;
            string name = accounts[idx][0];
            temp.push_back(name);
            for(auto each : x.second){
                temp.push_back(each);
            }
            res.push_back(temp);
        }
        return res;
    }
};