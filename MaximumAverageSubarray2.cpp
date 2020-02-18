class Solution {
public:
    int find(vector<int>& pre, int len){
        int sum = pre[len-1];
        int maxSum = pre[len-1];
        for(int i = len; i<pre.size(); i++){
            sum = pre[i] - pre[i - len];
            maxSum = max(maxSum , sum);
        }
        return maxSum ;
    }
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i<n; i++){
            pre[i] = pre[i-1] + nums[i];
        }
        double res = double(INT64_MIN);
        for(int len = k; len<=n; len++){
            int s = find(pre, len);
            if( res < (s * 1.0)/ len){
                res = (s * 1.0)/len;
            }
        }
        return res;
    }
};

//Approach 2 : by guessing the max average of the subarray using binary search and
//checking if the guessed average can be obtained from the any subarray of length k or more 
//by constructing prefixSum
class Solution {
public:
    bool check(vector<int>& nums, double& mid, int& k){        
        vector<double> prefixSum(nums.size() + 1);
        for(int i = 1; i< prefixSum.size(); i++){
            prefixSum[i]  = prefixSum[i-1] + (double)nums[i-1] - mid;
        }
        double prev = 0.0;
        for(int i = k; i < prefixSum.size(); ++i){
            if(prefixSum[i] > prev){
                return true;
            }
            prev = min(prev, prefixSum[i - k + 1]);
        }
        return false;
    }
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        double low = (double)minVal;
        double high = (double)maxVal;
        while(high - low > 10e-6){
            double mid = low + (high - low)/2;
            if(check(nums, mid, k)){
                low = mid;
            }else{
                high = mid;
            }
        }
        return low;
    }
};