class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.size() <= 1){
            return 1;
        }
        map<int, int> m;
        int degree = 0;
        vector<int> ele;
        for(int x : nums){
            if(m.find(x)!= m.end()){
                m[x] += 1;
                degree = max(degree, m[x]);
            }else{
                m.insert(make_pair(x, 1));
            }
        }
        set<int> s;
        map<int,int> left, right;
        for(int i = 0;i<nums.size();i++){
            if(m[nums[i]] == degree){
                s.insert(nums[i]);
                if(left.find(nums[i]) == left.end()){
                    left.insert(make_pair(nums[i], i));
                }else{
                    right[nums[i]] = i;
                }
            }
        }
        int ans = INT_MAX;
        for(int x : s){
            ans = min(ans, right[x] - left[x] + 1);
        }
        return ans==INT_MAX ? 1 : ans;
    }
};