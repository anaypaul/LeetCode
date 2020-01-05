class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto each : queries){
            int x = arr[each[0]];
            for(int i = each[0]+1; i<=each[1]; i++){
                x ^= arr[i];
            }
            res.push_back(x);
        }
        return res;
    }
};