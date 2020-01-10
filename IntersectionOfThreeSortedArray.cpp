class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int> res;
        int idx1 = 0;
        int idx2 = 0;
        int idx3 = 0;
        while(idx1<arr1.size() && idx2<arr2.size() && idx3<arr3.size()){
            if(arr1[idx1] == arr2[idx2] && arr2[idx2] == arr3[idx3]){
                res.push_back(arr1[idx1]);
                idx1++;
                idx2++;
                idx3++;
                continue;
            }
            int maxVal = max(max(arr1[idx1], arr2[idx2]), arr3[idx3]);
            if(arr1[idx1] < maxVal){
                idx1++;
            }
            if(arr2[idx2] < maxVal){
                idx2++;
            }
            if(arr3[idx3] < maxVal){
                idx3++;
            }
        }
        return res;
    }
};