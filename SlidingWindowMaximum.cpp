//Approach 1 : using stl 
// Time : O(n^2)
//Space : O(1)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        if(n == 0){
            return res;
        }
        for(int i = 0; i+k<=n; i++){
            res.push_back(*max_element(nums.begin()+i, nums.begin()+i+k));
        }
        return res;
    }
};
//Implementation 2
class Solution {
public:
    int query(int start, int end, vector<int>& nums){
        int max = nums[start];
        for(int i = start+1; i<=end; i++){
            if(max < nums[i]){
                max = nums[i];
            }
        }
        return max;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()== 0){
            return {};
        }
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> res;
        for(int i = 0; i<=nums.size()-k; i++){
            res.push_back(query(i, i+k -1, nums));
        }
        return res;
    }
};

//Approach 2 : Linear time solution
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1 || n == 0){
            return nums;
        }
        
        vector<int> left(n);
        left[0] = nums[0];
        vector<int> right(n);
        right[n-1] = nums[n-1];
        
        for(int i = 1; i<n; i++){
            //left part
            if(i%k == 0){
                left[i] = nums[i];
            }else{
                left[i] = max(left[i-1], nums[i]);
            }
            
            //right part
            int j = n-1-i;
            if((j+1) % k == 0){
                right[j] = nums[j];
            }else{
                right[j] = max(right[j+1], nums[j]);
            }
        }
        
        vector<int> res;
        for(int i = 0; i<n-k + 1; i++){
            res.push_back(max(left[i+k-1], right[i]));
        }
        return res;

    }
};