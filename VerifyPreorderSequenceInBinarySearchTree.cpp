class Solution {
public:    
    bool verifyPreorder(vector<int>& arr) {
        if(arr.empty()){
            return true;
        }
        stack<int> st;
        int secondMax = INT_MIN;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] < secondMax){
                return false;
            }
            while(!st.empty() && st.top() < arr[i]){
                secondMax = st.top();
                st.pop();
            }
            st.push(arr[i]);
        }
        return true;
    }
};