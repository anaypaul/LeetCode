/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
public:
    static bool mycmp(Interval v1, Interval v2){
        if(v1.start < v2.start){
            return true;
        }else if(v1.start > v2.start){
            return false;
        }else{
            if(v1.end < v2.end){
                return true;
            }
        }
        return false;
    }
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<Interval> v;
        for(auto each : schedule){
            for(auto y : each){
                v.push_back(y);
            }
        }
        sort(v.begin(), v.end(), mycmp);
        vector<Interval> res;
        for(int i = 0; i<v.size(); i++){
            if(res.empty() || res.back().end < v[i].start){
                res.push_back(v[i]);
            }else{
                res.back().end = max( res.back().end , v[i].end);
            }
        }
        vector<Interval> ans;
        for(int i = 1; i<res.size(); i++){
            ans.push_back(Interval(res[i-1].end, res[i].start));
        }
        return ans;
    }
};