class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            if(nums[0] == k){
                return 1;            
            }else{
                return 0;
            }
        }
        vector<int> pre(nums.size(), 0);
        int res = 0;
        pre[0] = nums[0];
        if(pre[0] == k){
            res++;
        }
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] == k){
                res++;
            }
            pre[i] = nums[i] + pre[i-1];
        }
        for(int len = 2; len<nums.size(); len++){
            for(int idx = len-1; idx<pre.size(); idx++){
                if(idx == len-1){
                    if(pre[idx] == k){
                        res++;
                    }
                }else{
                    if(pre[idx] - pre[idx-len] == k){
                        res++;
                    }
                }
            }
        }
        if(pre[nums.size()-1] == k){
            res++;
        }
        return res;
    }
};