class Solution {
public:
    static bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){ 
        return (a.second < b.second);      
    } 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        vector<pair<int, int>> arr;
        for(int i = 0;i<points.size();i++){
            int val = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pair<int, int> p = make_pair(i,val);
            arr.push_back(p);
        }
        
        sort(arr.begin(), arr.end(), sortbysec);
        
        for(int i = 0;i<K;i++){
            result.push_back(points[arr[i].first]);
        }
        return result;
    }
};