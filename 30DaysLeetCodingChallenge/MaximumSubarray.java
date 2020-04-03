class Solution {
    public int maxSubArray(int[] nums) {
        if (nums.length == 0) {
            return Integer.MIN_VALUE;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        int res = nums[0];
        int curr_max = nums[0];
        for (int i = 1; i < nums.length; i++) {
            curr_max = Math.max(curr_max + nums[i], nums[i]);
            res = Math.max(res, curr_max);
        }
        return res;
    }
}