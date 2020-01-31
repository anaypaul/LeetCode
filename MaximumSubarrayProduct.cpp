class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int res = nums[0];
        int curr_max_product = nums[0];
        int prev_min_product = nums[0];
        int prev_max_product = nums[0];
        for(int i = 1; i<nums.size(); i++){
            curr_max_product = max(prev_max_product * nums[i], max(prev_min_product * nums[i], nums[i]));
            int curr_min_product = min(min(prev_max_product * nums[i], prev_min_product * nums[i]), nums[i]);
            res = max(res, curr_max_product);
            prev_max_product = curr_max_product;
            prev_min_product = curr_min_product;
        }
        return res;
    }
};