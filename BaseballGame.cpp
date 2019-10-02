class Solution {
public:
    int calPoints(vector<string>& ops) {
        if (ops.empty()) return 0;      
        stack<int> st;
        int res = 0;
        for (int i=0; i<ops.size(); i++) {
            if (ops[i] == "C") {
                res -= st.top();
                st.pop();
            } else if (ops[i] == "D") {
                st.push(st.top()*2);
                res += st.top();
            } else if (ops[i] == "+") {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.push(val1);
                
                res += (val1+val2);
                st.push(val1+val2);
            } else {
                int x = stoi(ops[i]);
                res += x;
                st.push(x);
            }
        }
        return res;
    }
};