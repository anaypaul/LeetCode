class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int res = 0;
        while(arr.size() > 1){
            int prod = INT_MAX;
            int idx = -1;
            for(int i = 1; i<arr.size(); ++i){
                if(prod > arr[i-1] * arr[i]){
                    prod = arr[i-1] * arr[i];
                    idx = arr[i-1] < arr[i] ? i-1: i;
                }
            }
            res += prod;
            arr.erase(arr.begin() + idx);
        }
        return res;
    }
};