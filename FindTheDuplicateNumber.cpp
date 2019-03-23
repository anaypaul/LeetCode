class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = -1;
        for(int i = 0;i<nums.size();i++){
            if(nums[abs(nums[i]) - 1] >0 ){
                nums[abs(nums[i])-1] *= -1;
            }else{
                cout<<abs(nums[i])<<endl;
                res = abs(nums[i]);
                break;
            }
        }
        return res;
    }
};