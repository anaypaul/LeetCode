class Solution {
public:
    long long int getSum(vector<int> arr, int val){
        long long int sum = 0;
        for(int i = 0; i<arr.size(); i++){
            if(val > arr[i]){
                sum += arr[i];
            }else{
                sum += val;
            }
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int res = *max_element(arr.begin(), arr.end());
        if(sum == target){
            return res;
        }
        int n = arr.size();
        int low = 0;
        int high = 100000;
        int noUpdate = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            int currSum = getSum(arr, mid);
            cout<<currSum<<endl;
            if(currSum < target){
                low = mid + 1;
            }else if(currSum > target){
                high = mid -1;
            }else if(currSum == target){
                return mid;
            }
            if(abs(getSum(arr, res) - target) > abs(currSum - target)){
                res = mid;
                noUpdate = 0;
            }else if(abs(getSum(arr, res) - target) == abs(currSum - target)){
                res = min(res, mid);
                noUpdate++;
                if(noUpdate> 100){
                    return res;
                }
            }
        }
        return res;
    }
};