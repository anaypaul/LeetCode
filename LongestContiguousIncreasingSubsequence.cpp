class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int start = 0;
        int prev = nums[start];
        int maxLen = 1;
        for(int end = 1;end<nums.size();end++){
            if(nums[end] > prev){
                maxLen = max(maxLen, end - start + 1);
                prev = nums[end];
            }else{
                start = end;
                prev = nums[start];
            }
        }
        return maxLen;
    }
};