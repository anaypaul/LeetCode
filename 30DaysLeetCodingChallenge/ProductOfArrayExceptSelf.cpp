class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 1);
        int p = 1;
        for(int i = 1; i<nums.size(); i++){
            arr[i] = nums[i-1] * arr[i-1];
        }
        
        for(int i = nums.size() - 2; i>=0; i--){
            p = p * nums[i+1];
            arr[i] *= p;
        }
        return arr;
    }
};