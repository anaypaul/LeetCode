class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.size() == 0){
            return 0;
        }
        
        int n = costs.size();
        int k = costs[0].size();
        for(int i = 1; i<n; i++){
            for(int curr = 0; curr<k; curr++){
                int minVal = INT_MAX;
                for(int j = 0; j<k; j++){
                    if(curr != j){
                        minVal =  min(minVal, costs[i-1][j]);
                    }
                }
                costs[i][curr] += minVal;
            }
        }
        return *min_element(costs[n-1].begin(), costs[n-1].end());
    }
};