class Solution {
public:
    static bool mycmp(vector<int> v1, vector<int> v2){
        return v1[0] < v2[0];
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()== 0){
            return true;
        }
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i<intervals.size()-1; i++){
            if(intervals[i][1] > intervals[i+1][0]){
                return false;
            }
        }
        return true;
    }
};