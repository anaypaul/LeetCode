class Solution {
public:
    long long int mydivide(long long int y, long long int x){
        return (long long int)ceil((double)y/(double)x);
    }
    long long int calculate(vector<int> nums, long long int d, long long int threshold){
        long long int res= 0;
        for(int i = 0; i<nums.size(); i++){
            res += mydivide((long long int)nums[i], d);
        }
        if(res <=(long long int)threshold){
            return res;
        }
        return INT_MAX;
    }
    int smallestDivisor(vector<int>& nums, long long int threshold) {
        long long int left = 1;
        long long int right = *max_element(nums.begin(), nums.end());
        long long int res = INT_MAX;
        while(left <= right){
            long long int mid = left + (right - left)/2;
            long long int result = calculate(nums, mid, threshold);
            if( result <= threshold){
                res = min(res, mid );
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return res;
    }
};