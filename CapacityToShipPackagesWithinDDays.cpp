//Approach 1: using binary search checking different weight value within the 
//required range 
//Time : O(N log N)
class Solution {
public:
    bool check(vector<int> w , long long int cap, int D){
        int days = 1;
        int i = 0;
        for(i = 0; i<w.size();){
            long long int curr_sum= 0;
            while(i<w.size() && curr_sum + w[i] <=cap){
                curr_sum += w[i];
                i++;
            }
            curr_sum = 0;
            if(days >D){
                return false;
            }
            days++;
        }
        return true;
    }
    int shipWithinDays(vector<int>& w, int D) {
        if(D == w.size()){
            return *max_element(w.begin(), w.end());
        }
        if( D == 1){
            return accumulate(w.begin(), w.end(), 0);
        }
        long long int total = accumulate(w.begin(), w.end(), 0);
        long long int maxVal = *max_element(w.begin(), w.end());
        long long int low = maxVal;
        long long int high = total;
        long long int res = INT_MAX;
        while(low <= high){
            long long int mid = low + (high - low)/2;
            if(check(w, mid, D)){
                high = mid-1;
                res = min(res, mid);
            }else{
                low = mid +1;
            }
        }
        return res;
    }
};