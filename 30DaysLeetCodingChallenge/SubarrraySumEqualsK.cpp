class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        vector<int> arr(nums.size() + 1, 0);
        for(int i = 1; i<nums.size()+1; i++){
            arr[i] = nums[i-1] + arr[i-1];
        }
        for(int i= 0; i<nums.size(); i++){
            for(int j = i + 1; j<=nums.size(); j++){
                if(arr[j] - arr[i] == k){
                    res++;
                }
            }
        }
        return res;
    }
};