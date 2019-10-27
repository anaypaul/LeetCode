class Solution {
public:
    int splitArray(vector<int>& w, int D) {
        int res = INT_MAX;
        int low = 0;
        long long int high = 0;
        for(auto x : w){
            low = max(low, x);
            high += x;
        }
        
        while(low < high){
            long long int mid = low + (high - low)/2;
            long long int days = 1;
            long long int curr_sum = 0;
            for(auto each : w){
                if(curr_sum + each > mid ){
                    days++;
                    curr_sum = 0;
                }
                curr_sum += each;
            }
            if(days > D){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return low;
    }
};