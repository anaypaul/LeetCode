class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int low = 0;
        int high = nums.size()-1;
        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[mid] > nums[mid+1]){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};