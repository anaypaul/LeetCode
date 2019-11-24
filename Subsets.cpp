//Iterative Approach using bit manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> res;
        int mask = 1 << nums.size();
        for(int i = 0; i<mask; i++){
            vector<int> temp;
            for(int j = 0; j<nums.size(); j++){
                if(i &(1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            res.push_back(temp);
        }
        return res;
        
    }
};

//Recursive approach 
class Solution {
public:
    void helper(int index, vector<vector<int>>& res, vector<int>& temp, vector<int>& nums){
        if(index == nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        helper(index +1, res, temp, nums);
        temp.pop_back();
        helper(index + 1, res, temp, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(0, res, temp, nums);
        return res;
    }
};