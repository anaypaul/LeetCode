class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int contains = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 1){
                contains++;
                break;
            }
        }
        if(contains == 0){
            return 1;
        }
        
        for(int i = 0;i<nums.size();i++){
            if(nums[i]<=0 || nums[i]>n){
                nums[i] = 1;
            }
        }
        
        for(int i = 0;i<nums.size();i++){
            nums[abs(nums[i])-1] = -1 * abs(nums[abs(nums[i])-1]);
        }
        
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>=0){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};