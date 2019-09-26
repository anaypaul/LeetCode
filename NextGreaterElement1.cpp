class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        for(int i = 0;i<nums2.size(); i++){
            um[nums2[i]] = i;
        }
        stack<int> st;
        vector<int> NGE;
        for(int i = nums2.size()-1 ; i>=0 ; i--){
            if(st.empty()){
                NGE.push_back(-1);
                st.push(nums2[i]);
            }
            else{
                if(st.top() > nums2[i]){
                    NGE.push_back(st.top());
                    st.push(nums2[i]);
                }
                else{
                    while(!st.empty() && st.top() <=nums2[i]){
                        st.pop();
                    }
                    if(!st.empty()){
                        NGE.push_back(st.top());
                        st.push(nums2[i]);
                    }else{
                        NGE.push_back(-1);
                        st.push(nums2[i]);
                    }
                }
            }
        }
        
        reverse(NGE.begin(), NGE.end());
        vector<int> res;
        for(int i = 0;i<nums1.size(); i++){
            res.push_back(NGE[um[nums1[i]]]);
        }
        return res;
    }
};