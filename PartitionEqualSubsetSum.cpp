//Brute force implementation 
// Time : O(2^n)
// Space : O(n)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0){
            return false;
        }
        
        return helper(nums, sum/2, 0);
    }
    bool helper(vector<int>& nums, int sum , int curr){
        if(sum == 0){
            return true;
        }
        
        if(curr >= nums.size() || nums.size() == 0){
            return false;
        }
        
        if(helper(nums, sum, curr + 1)){
            return true;
        }
        if(nums[curr] <= sum ){
            return helper(nums, sum - nums[curr], curr + 1);
                        
        }
        return false;
    }
};

//Bottom Up DP
// Time : O(n * s) n = number of items , s = sum/2
// Space: O(n * s) for dp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0){
            return false;
        }
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum/2 + 1 , false));
        dp[0][0] = true;
        for(int i = 0; i<nums.size(); i++){
            dp[i][0] = true;
        }
        for(int i = 1; i<nums.size(); i++){
            for(int s = 0; s<= sum/2; s++ ){
                dp[i][s] = dp[i-1][s] || ( nums[i]<=s ? dp[i-1][s-nums[i]] : false );
            }
        }
        return dp[nums.size()-1 ][sum/2];
    }
};

//Approach 3 : Top Down with memoization
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2){
            return false;
        }
        int n = nums.size();
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return helper(nums, 0, target, dp);
        
    }
    bool helper(vector<int>& nums, int curr, int target, vector<vector<int>>& dp){
        cout<<"target"<<target<<endl;
        if(target == 0){
            return true;
        }
        if(curr >= nums.size() || nums.size() == 0){
            return false;
        }
        if(dp[curr][target] != -1){
            return dp[curr][target];   
        }
        
        if(nums[curr] <= target){
            if(helper(nums, curr + 1, target - nums[curr], dp)){
                dp[curr][target] = 1;
                return true;
            }
        }
        dp[curr][target] = helper(nums, curr + 1, target, dp) ? 1 : 0;
        return dp[curr][target] == 1 ? true: false;
        
    }
};