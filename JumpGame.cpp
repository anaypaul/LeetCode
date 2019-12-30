//Approach 1 : backtracking using dfs.
class Solution {
public:
    bool check(int i, int n){
        return i>=0 && i<n;
    }
    void dfs(int curr , vector<int> & nums, vector<bool>& vis){
        if(curr == nums.size() -1){
            vis[nums.size()-1] = true;
            return;
        }
        if(check(curr, nums.size()) == false){
            return ;
        }
        if(vis[curr] == true){
            return ;
        }
        vis[curr] = true;
        for(int i = 1; i<= nums[curr]; i++){
            dfs(curr + i, nums, vis);
        }
        vis[curr] = false;
    }
    bool canJump(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        vector<bool> vis(n , false);
        int start = 0;
        dfs(0, nums, vis);
        return vis[n-1];
    }
};

//Approach 2 : using BFS
class Solution {
public:
    bool canJump(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        vector<bool> vis(n , false);
        int start = 0;
        queue<int> q;
        q.push(start);
        vis[start] = true;
        while(!q.empty()){
            auto curr = q.front();
            if(curr == n-1){
                return true;
            } 
            for(int jumpSize = 1; jumpSize <=nums[curr]; jumpSize++ ){
                if(curr + jumpSize<n && !vis[curr + jumpSize]){
                    if(curr + jumpSize == n -1 ){
                        return true;
                    }
                    q.push(curr + jumpSize);
                    vis[curr + jumpSize] = true;
                }
            }
            q.pop();
        }
        return vis[n-1];
    }
};

//Approach 3
class Solution {
public:
    bool canJump(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        vector<bool> vis(n , false);
        int currMax = 0;
        for(int i = 0; i<n; i++){
            currMax = max(currMax, i + nums[i]);
            if(currMax >= n-1){
                return true;
            }
            if(nums[i] == 0 && currMax <= i){
                return false;
            }
        }
        return true;
    }
};