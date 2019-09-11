class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        vector<int> L(nums.size(), 0);
        L[0] = 1;
        for(int i = 1;i<nums.size();i++){
            for(int j = 0;j<i;j++){
                if(nums[i] > nums[j] && L[j] > L[i]){
                    L[i] = L[j];
                }
            }
            L[i]++;
        }
        return *max_element(L.begin(), L.end());
    }
};