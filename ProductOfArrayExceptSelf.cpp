class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        vector<int> L(arr.size(), 1);
        vector<int> R(arr.size(), 1);
        for(int i =1 ; i<arr.size(); i++){
            L[i] = L[i-1] * arr[i-1]; 
        }
        for(int i = arr.size()-2; i>=0; i--){
            R[i] = R[i+1] * arr[i+1];
        }
        vector<int> res;
        for(int i = 0; i<arr.size(); i++){
            res.push_back(L[i] * R[i]);
        }
        return res;
    }
};