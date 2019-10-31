class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<pair<int,int>> nge(n, {-1,-1});
        stack<pair<int,int>> st;
        for(int i = n-1; i>=0 ; i--){
            if(st.empty()){
                nge[i] = make_pair(-1,-1);
            }else{
                while(!st.empty() && T[i] >= st.top().first){
                    st.pop();
                }
                if(st.empty()){
                    nge[i] = make_pair(-1,-1);
                }else{
                    nge[i] = make_pair(st.top().first, st.top().second);
                }
            }
            st.push(make_pair(T[i],i));
        }
        vector<int> res(n, 0);
        for(int i = 0; i<nge.size();i++){
            if(nge[i].first != -1){
                res[i] = nge[i].second - i;
            }
        }
        return res;
    }
};