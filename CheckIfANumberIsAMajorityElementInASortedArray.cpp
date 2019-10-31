//Approach 1 : find major element and check count > n/2 
//linear time and constant space
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int candidate = nums[0];
        int count = 1;
        for(int i = 0; i<nums.size(); i++){
            if(candidate == nums[i]){
                count++;
            }
            else{
                count--;
                if(count == 0){
                    count = 1;
                    candidate = nums[i];
                }
            }
        }
        int c = 0;
        for(auto x : nums){
            if(x == candidate){
                c++;
            }
        }
        return candidate == target && c > nums.size()/2;
    }
};

//Approach 2
//linear time and constant space
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int count = 0;
        for(auto x : nums){
            if(target == x){
                count++;
            }
        }
        return count > nums.size()/2;
    }
};

//Approach 3
//Using binary search to get start and end index in O(log n) time and check the count of the target
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        bool found = false;
        int start = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] >= target){
                if(nums[mid] == target){
                    found = true;
                    start = mid;
                }
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        if(!found){
            return false;
        }
        int end = -1;
        low = 0;
        high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                end = mid;
                low = mid + 1;
            }else if(nums[mid] > target){
                high = mid - 1;
            }else if(nums[mid] < target){
                low = mid + 1;
            }
        }
        return found && end - start + 1 > nums.size()/2;
    }
};
