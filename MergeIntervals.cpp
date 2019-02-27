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
    // bool compareInterval(Interval i1, Interval i2) { 
    //     return (i1.start < i2.start); 
    // } 
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