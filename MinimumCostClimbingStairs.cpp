class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int start0 = cost[0];
        int start1 = cost[1];
        for(int i = 2;i<cost.size();i++){
            int curr = cost[i] + min(start0, start1);
            start0 = start1;
            start1 = curr;
        }
        return min(start0, start1);
    }
};