class Solution {
public:
    string vec2string(vector<int>& arr){
        string res = "";
        for(auto x : arr){
            res += to_string(x) + "#";
        }
        return res;
    }
    void helper(int curr, vector<int>& v, vector<int>& nums, vector<vector<int>>& res, unordered_set<string>& s){
        if(curr == nums.size()){
            string x = vec2string(v);
            if(s.find(x) == s.end()){
                res.push_back(v);
                s.insert(x);
            }
            return ;
        }
        v.push_back(nums[curr]);
        helper(curr + 1, v, nums, res, s);
        v.pop_back();
        helper(curr + 1, v, nums, res, s);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        unordered_set<string> s;
        vector<vector<int>> res;
        vector<int> v;
        sort(nums.begin(), nums.end());
        helper(0, v, nums, res, s);
        return res;
    }
};