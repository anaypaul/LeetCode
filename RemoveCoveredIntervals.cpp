class Solution {
public:
    static bool mycmp(vector<int>& a, vector<int>& b){
        if(a[0] < b[0]){
            return true;
        }else if(a[0] == b[0]){
            if(a[1] < b[1]){
                return true;
            }
        }
        return false;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), mycmp);
        int res = intervals.size();
        vector<int> curr = intervals[0];
        for(int i = 1; i<intervals.size(); i++){
            if(curr[0]<= intervals[i][0] && intervals[i][1] <= curr[1]){
                res--;
            }else{
                curr[0] = intervals[i][0];
                curr[1] = intervals[i][1];
            }
        }
        return res;
    }
};