class Solution {
public:
    string vec2string(vector<int>& arr){
        string res = "";
        for(int i = 0; i<arr.size(); i++){
            res += to_string(arr[i]) + " ";
        }
        return res;
    }
    void helper(int curr, vector<int>& nums, vector<vector<int>>& res, unordered_set<string>& s){
        if(curr == nums.size()){
            string t = vec2string(nums);
            if(s.find(t) == s.end()){
                s.insert(t);
                res.push_back(nums);
            }
            return ;
        }
        for(int i = curr; i<nums.size(); i++){
            swap(nums[i], nums[curr]);
            helper(curr + 1, nums, res, s);
            swap(nums[i], nums[curr]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> res;
        unordered_set<string> s;
        helper(0, nums, res, s);
        return res;
    }
};