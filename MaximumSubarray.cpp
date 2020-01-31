class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int currSum = nums[0];
        int maxSum = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(currSum + nums[i] > nums[i]){
                currSum += nums[i];
            }else{
                currSum = nums[i];
            }
            maxSum = max(maxSum , currSum);
        }
        return maxSum;
    }
};