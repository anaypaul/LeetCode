class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        stack<int> st;
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            while(!st.empty() && st.top()> nums[i]){
                st.pop();
            }
            st.push(nums[i]);
            res += st.size();
        }
        return res;
    }
};