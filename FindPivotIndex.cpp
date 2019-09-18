class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==0){
            return -1;
        }
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        partial_sum(nums.begin(), nums.end(), left.begin());
        partial_sum(nums.rbegin(), nums.rend(), right.begin());
        for(int i = 0;i<nums.size();i++){
            if(left[i] == right[nums.size()-1-i]){
                return i;
            }
        }
        return -1;
    }
};