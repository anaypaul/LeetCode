class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(intervals.size()== 0){
            return 0;
        }
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        for(int i = 1; i<intervals.size(); i++){
            if(intervals[i][0] >= pq.top()){
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};