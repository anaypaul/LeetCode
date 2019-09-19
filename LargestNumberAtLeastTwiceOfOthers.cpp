class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > nums[largest]){
                largest = i;
            }
        }
        for(int i = 0; i<nums.size();i++){
            if(i != largest){
                if( nums[i]*2 > nums[largest]){
                    return -1;
                }
            }
        }
        return largest;
    }
};