class Solution {
public:
    void helper(int curr, vector<int> nums, vector<vector<int>>& res){
        if(curr == nums.size()){
            res.push_back(nums);
            return ;
        }
        for(int i = curr; i<nums.size(); i++){
            swap(nums[curr], nums[i]);
            helper(curr+1, nums, res);
            swap(nums[curr], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> res;
        helper(0, nums, res);
        return res;
    }
};