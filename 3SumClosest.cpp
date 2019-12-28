class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for(int i= 0; i< nums.size() - 2; i++){
            int j = i+1;
            int k = nums.size() -1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < abs(res - target)){
                    res = sum;
                }
                if(sum < target){
                    j++;
                }else if(sum > target){
                    k--;
                }else{
                    return target;
                }
            }
        }
        return res;
    }
};