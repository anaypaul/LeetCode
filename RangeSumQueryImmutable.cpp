class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int>& nums) {
        dp.push_back(0);
        for(auto x : nums){
            dp.push_back(dp[dp.size()-1] + x);
        }
    }
    
    int sumRange(int i, int j) {
        j++;
        return dp[j]- dp[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */