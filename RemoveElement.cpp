class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = -1;
        for(int i = 0;i<nums.size();){
            if(nums[i] == val){
                i++;
            }else{
                nums[index+1] = nums[i];
                index++;
                i++;
            }
        }
        return index + 1;
    }
};