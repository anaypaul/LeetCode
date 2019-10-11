class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        unordered_map<int,int> um;
        int res = 0;
        int start = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0 && um.find(nums[i]) == um.end()){
                um[0] = i;
            }else if(nums[i] == 0 && um.find(nums[i]) != um.end()){
                start = um[0] + 1;
                um[0] = i;
            }
            res = max(res, i-start+1);
        }
        return res;
    }
};