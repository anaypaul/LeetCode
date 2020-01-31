class Solution {
public:
    int helper(vector<int>& nums, int idx, int target){
        int sum = 0;
        int low = idx;
        int high = nums.size() - 1;
        while(low < high){
            int val = nums[low] + nums[high];
            if(val < target){
                sum += high - low;
                low++;
            }else{
                high--;
            }
        }
        return sum;
    }
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += helper(nums, i+1, target - nums[i]);
        }
        return sum;
    }
};