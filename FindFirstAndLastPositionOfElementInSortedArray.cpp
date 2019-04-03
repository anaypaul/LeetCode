class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = left + (right - left)/2;
            if(mid <nums.size() && nums[mid] >= target){
                right = mid-1;
            }else{
                left = mid + 1;
            }
        }
        if(right+1< nums.size() && nums[right+1] == target){
            res.push_back(right+1);    
        }else{
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        
        left= 0;
        right = nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(left < nums.size() && nums[mid]> target){
                right = mid-1;
            }else{
                left = mid + 1;
            }
        }
        res.push_back(right);
        return res;
    }
};