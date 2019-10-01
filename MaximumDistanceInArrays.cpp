class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int res = INT_MIN;
        int minVal = a[0][0];
        int maxVal = a[0][a[0].size()-1];
        for(int i = 1; i<a.size(); i++){
            res = max(res, abs(a[i][a[i].size()-1] - minVal) );
            res = max(res, abs(a[i][0] - maxVal));
            if(minVal > a[i][0]){
                minVal = a[i][0];
            }
            if(maxVal < a[i][a[i].size()-1]){
                maxVal = a[i][a[i].size()-1];
            }
        }
        return res;
    }
};