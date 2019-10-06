class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        vector<int> arr(2, 0);
        for(auto x: chips){
            arr[x%2]++;
        }
        return min(arr[0], arr[1]);
    }
};