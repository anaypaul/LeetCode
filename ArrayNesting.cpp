class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<bool> vis(nums.size(), false);
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            int curr = i;
            int len = 0;
            while(vis[curr] == false){
                vis[curr] = true;
                len++;
                curr = nums[curr];
                res = max(res, len);
            }
        }
        return res;
    }
};