class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long  max1 = LONG_MIN;
        long long  max2 = LONG_MIN;
        long long  max3 = LONG_MIN;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }else if(max1 >nums[i] && nums[i] > max2){
                max3 = max2;
                max2 = nums[i];
            }else if(max2>nums[i]  && nums[i] > max3){
                max3 = nums[i];
            }
        }
        return max3 != LONG_MIN ? max3 : *max_element(nums.begin(), nums.end());
    }
};