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
//2nd solution using STL bsearch.
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.empty()){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        vector<int>::iterator lower,upper;
        lower = lower_bound(nums.begin(), nums.end(), target );
        upper = upper_bound(nums.begin(), nums.end(), target );
        int start = lower - nums.begin();
        int end = upper - nums.begin()-1;
        if((start>=nums.size() || start<0)||nums[start] != target ){
            res.push_back(-1);
            res.push_back(-1);
        }else{
            res.push_back(start);
            res.push_back(end);
        }
        return res;
    }
};