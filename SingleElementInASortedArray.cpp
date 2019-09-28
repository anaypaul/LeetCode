//Approach 1
//Time : O(n)
//Space : O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x = nums[0];
        for(int i = 1;i<nums.size(); i++){
            x = x^nums[i];
        }
        return x;
    }
};

//Approach 2
//Time : O(log n)
//Space : O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while(low < high){
            int mid = low + (high - low)/2;
            if((mid%2 == 1 && nums[mid] == nums[mid-1]) || ( mid%2== 0 && nums[mid] == nums[mid+1])){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return nums[low];
    }
};