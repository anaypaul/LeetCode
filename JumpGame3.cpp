class Solution {
public:
    bool ans;
    Solution(){
        ans = false;
    }
    bool check(int i, int n){
        return i>=0 && i<n;
    }
    int dir[2] = {1, -1};
    void dfs(int currIndex, vector<int>& arr,vector<bool> vis,  bool& res){
        if(ans == true){
            return;
        }
        if(!check(currIndex, arr.size())){
            return ;
        }
        if(vis[currIndex] == true){
            return ;
        }
        if(arr[currIndex] == 0){
            res = true;
            ans = true;
            return;
        }
        vis[currIndex] = true;
        dfs(currIndex + arr[currIndex], arr, vis, res);
        dfs(currIndex - arr[currIndex], arr, vis, res);
        vis[currIndex] = false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), false);
        bool res = false;
        dfs(start, arr,vis, res);
        return ans;

    }
};