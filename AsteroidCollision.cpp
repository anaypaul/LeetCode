class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int> res;
        stack<int> st;
        for(int i = 0; i<arr.size(); ){
            int next = arr[i];
            if(next > 0){
                st.push(next);
                i++;
            }else{
                if(st.empty() || (st.top()<0)){
                    st.push(next);
                    i++;
                }else{
                    if(st.top() == abs(next)){
                        st.pop();
                        i++;
                    }else if(st.top() > abs(next)){
                        i++;
                    }else if(st.top() < abs(next)){
                        st.pop();
                        next = next;
                    }
                }
            }
        }        
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};