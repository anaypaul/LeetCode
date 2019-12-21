class Solution {
public:
    void helper(int i, vector<int>& nums, int target, int& res, int sum){
        if(i == nums.size()){
            if(sum == target){
                res++;
                return ;
            }
            return ;
        }
        helper(i+1, nums, target, res, sum + nums[i]);
        helper(i+1, nums, target, res, sum - nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int res = 0;
        helper(0, nums, S, res, 0);
        return res;
    }
};