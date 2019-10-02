class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            st.push(nums[i]);
        }
        for(int i = nums.size()-1; i>=0; i--){
            if(st.empty()){
                res.push_back(-1);
                st.push(nums[i]);
            }else{
                while(!st.empty() && st.top() <= nums[i]){
                    st.pop();
                }
                if(!st.empty()){
                    res.push_back(st.top());
                }else{
                    res.push_back(-1);
                }
                st.push(nums[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};