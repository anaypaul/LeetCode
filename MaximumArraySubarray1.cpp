class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<int> v;
        int total = 0;
        for(int i = 0;i<nums.size();i++){
            if(i<k-1){
                total += nums[i];
            }else if(i== k-1){
                total += nums[i];
                v.push_back(total);
            }else{
                total += nums[i] - nums[i-k];
                v.push_back(total);
            }
            
        }
        int res = *max_element(v.begin(), v.end());
        return (double)(res/(double)k);
    }
};