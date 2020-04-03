class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0){
            return INT_MIN;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        int res = nums[0];
        int curr_max = nums[0];
        for(int i = 1; i<nums.size();i++){
            curr_max = max(nums[i], nums[i] + curr_max);
            res = max(res, curr_max);
        }
        return res;
    }
};