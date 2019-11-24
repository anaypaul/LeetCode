// [TLE] 
// Intuition : generate all possible combinations of parentheses and check if valid using a stack
class Solution {
public:
    vector<char> constructString(int n){
        vector<char> res;
        for(int i = 0; i<n; i++){
            res.push_back('(');
        }
        for(int i = 0; i<n; i++){
            res.push_back(')');
        }
        return res;
    }
    void helper(int curr, vector<char> arr, vector<vector<char>>& allCombos){
        if(curr == arr.size()){
            allCombos.push_back(arr);
            return;
        }
        for(int i = curr; i<arr.size(); i++){
            swap(arr[curr], arr[i]);
            helper(curr+1, arr, allCombos);
            swap(arr[curr], arr[i]);
        }
    }
    bool check(vector<char> s){
        stack<char> st;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else{
                if(st.empty()){
                    return false;
                }
                st.pop();
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
    vector<string> generateParenthesis(int n) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        set<string> res;
        vector<char> arr = constructString(n);
        vector<vector<char>> allCombos;
        helper(0, arr, allCombos);
        for(auto x : allCombos){
            if(check(x)){
                string t = "";
                for(auto y : x){
                    t += y;
                }
                res.insert(t);
            }
        }
        vector<string> t(res.begin(), res.end());
        return t;
    }
};

//Accepted solution
class Solution {
public:
    void helper(int n, int nleft, int nright, string& s, vector<string>& res){
        if(n == nleft && n == nright){
            res.push_back(s);
            return;
        }
        if(nleft < n){
            s.push_back('(');
            helper(n, nleft+1, nright, s, res);
            s.pop_back();
        }
        if(nright < nleft){
            s.push_back(')');
            helper(n, nleft, nright+1, s, res);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<string> res;
        string s = "";
        helper(n, 0, 0, s, res);
        return res;
    }
};