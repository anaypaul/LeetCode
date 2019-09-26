class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum_arr(0);
        sum_arr.push_back(nums[0]);
        for(int i = 1;i<n;i++){
            sum_arr.push_back(nums[i] + sum_arr[i-1]);
        }
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                int sum = sum_arr[j] - sum_arr[i] + nums[i];
                if(sum == k || (k != 0 && sum %k == 0 ) ){
                    return true;
                }
            }
        }
        cout<<endl;
        return false;
    }
};
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2){
            return false;
        }
        if(k==0){
            for(int i = 1;i<n;i++){
                if(nums[i] == 0 && nums[i-1]==0){
                    return true;
                }
            }
            return false;
        }else{
            int i = 0;
            unordered_map<int, int> res;
            while(true){
                if(i!=0 && nums[i]%k == 0){
                    return true;
                }else{
                    if(res.find(nums[i]%k) == res.end()){
                        res.insert(make_pair(nums[i]%k, i));
                    }else{
                        if(i - res[nums[i]%k] > 1){
                            return true;
                        }
                    }
                }
                i++;
                if(nums.size() == i){
                    return false;
                }
                nums[i] += nums[i-1];
            }
        }
        return false;
    }
};