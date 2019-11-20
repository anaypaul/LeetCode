class Solution {
public:
    int query(int start, int end, vector<int>& nums){
        int max = nums[start];
        for(int i = start+1; i<=end; i++){
            if(max < nums[i]){
                max = nums[i];
            }
        }
        return max;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()== 0){
            return {};
        }
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> res;
        for(int i = 0; i<=nums.size()-k; i++){
            res.push_back(query(i, i+k -1, nums));
        }
        return res;
    }
};