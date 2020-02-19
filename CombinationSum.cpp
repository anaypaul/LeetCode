class Solution {
public:
    void helper(int curr, vector<int>& arr, vector<int> temp, vector<vector<int>>& res, int target, int currSum){
        if(currSum > target || curr >= arr.size()){
            return ;
        }
        if(currSum == target){
            res.push_back(temp);
            return ;
        }
        if(currSum + arr[curr] <= target){
            temp.push_back(arr[curr]);
            helper(curr, arr, temp, res, target, currSum + arr[curr]);
            temp.pop_back();
        }
        helper(curr +1, arr, temp, res, target, currSum);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(0, arr, temp, res, target, 0);
        return res;
    }
};