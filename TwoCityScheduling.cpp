class Solution {
public:
    static bool mycmp(vector<int>& a, vector<int>& b){
        return a[1] - a[0] > b[1] - b[0];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // 10, 170, -350, -10
        sort(costs.begin(), costs.end(), mycmp);
        int n = costs.size();
        int res = 0;
        for(int i = 0; i<n/2; i++){
            res += costs[i][0];
        }
        for(int i = n/2 ; i<n; i++){
            res += costs[i][1];
        }
        return res;
    }
};