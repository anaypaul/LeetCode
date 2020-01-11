class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int> res;
        for(int i = 0; i<nums.size(); i = i+2){
            for(int j = 0; j<nums[i]; j++){
                res.push_back(nums[i+1]);
            }
        }
        return res;
    }
};