class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(ops.size() == 0){
            return m * n;
        }
        int i = INT_MAX;
        int j = INT_MAX;
        for(auto each : ops){
            i = min(i, each[0]);
            j = min(j, each[1]);
        }
        return i*j;
    }
};