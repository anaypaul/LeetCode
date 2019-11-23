// [TLE]
class Solution {
public:
    int binarySearch(vector<pair<int,int>> arr, int target){
        int low = 0;
        int high = arr.size();
        while(low < high){
            int mid = low + (high - low)/2;
            if(arr[mid].first == target){
                high = mid;
            }else if(arr[mid].first < target){
                low = mid+1;
            }else if(arr[mid].first > target){
                high = mid;
            }
        }
        return low < arr.size() ? arr[low].second : -1;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(intervals.size() == 0 || intervals.size()== 1){
            return {-1};
        } 
        vector<pair<int,int> > arr(intervals.size()); //start, index pair
        for(int i = 0; i<intervals.size(); i++){
            arr[i] = make_pair(intervals[i][0], i);
        }
        sort(arr.begin(), arr.end());
        vector<int> res;
        for(int i = 0; i<intervals.size(); i++){
            int x = intervals[i][1];
            res.push_back(binarySearch(arr, x));
        }
        return res;
    }
};