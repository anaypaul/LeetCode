/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compareInterval(Interval i1, Interval i2) { 
        return (i1.start < i2.start); 
    } 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> answer;
        sort(intervals.begin(), intervals.end() , compareInterval);
        for(int i = 0;i<intervals.size();i++){
            cout<<intervals[i].start<<" "<<intervals[i].end<<endl;
        }
        for(int i = 0;i<intervals.size(); i++){
            int start = intervals[i].start;
            int end = intervals[i].end;
            while(i+1<intervals.size() && end>= intervals[i+1].start){
                end = max(intervals[i+1].end,end);
                i++;
            }
            answer.push_back(Interval(start, end));
        }
        return answer;
    }
};

//updated solution based on updated question and test cases. 
class Solution {
public:
    static bool mycmp(vector<int>& a, vector<int>& b ){
        if(a[0] < b[0]){
            return true;
        }else if(a[0] == b[0]){
            if(a[1] < b[1]){
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), mycmp);
        for(int i = 0;i<intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            while(i+1 < intervals.size() && end >= intervals[i+1][0]){
                end = max(intervals[i+1][1], end);
                i = i + 1;
            }
            res.push_back({start, end});   
        }
        return res;
    }
};