class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = INT_MAX;
        for(int i = 0;i<arr.size()-1;i++){
            diff = min(diff, arr[i+1]- arr[i]);
        }
        vector<vector<int>> res;
        for(int i = 0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i] == diff){
                vector<int> t;
                t.push_back(min(arr[i+1], arr[i]));
                t.push_back(max(arr[i], arr[i+1]));
                res.push_back(t);
            }
        }
        return res;
    }
};