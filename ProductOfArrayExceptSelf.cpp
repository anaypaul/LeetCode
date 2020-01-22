//Time complexity : O(n)
//Space complexity : O(n)
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
// Time Complexity : O(n)
// Space Complexity : O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1 );
        int p = 1;
        for(int i = 1; i<n; i++){
            res[i] = res[i-1] * nums[i-1];
        }
    
        p = 1;
        for(int i = n-2; i>=0; i--){
            p *= nums[i+1];
            res[i] *= p;
        }
        
        return res;
    }
};