class Solution {
    public void moveZeroes(int[] nums) {
        int idx = -1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                int t = nums[idx + 1];
                nums[idx + 1] = nums[i];
                nums[i] = t;
                idx++;
            }
        }
    }
}