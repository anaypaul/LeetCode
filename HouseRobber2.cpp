class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        if(n==2){
            return max(nums[0], nums[1]);
        }
        if(n==1){
            return nums[0];
        }
        int res = 0;
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i<nums.size()-1; i++ ){
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        res = max(res, dp[n-2]);
        // cout<<"by choosing starting from 0th element :"<<res<<endl;
        for(int i = 0; i<dp.size(); i++){
            dp[i] = 0;
        }
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        for(int i = 3; i<dp.size(); i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        // cout<<"by choosing starting from 1st element: "<<dp[n-1]<<endl;
        res = max(res, dp[n-1]);
        return res;
        
    }
};