class Solution {
public:
    void permute(string curr, string rest, vector<string>& res, int n){
        if(rest == ""){
            res.push_back(curr);
        }else{
            for(int i = 0; i<rest.size(); i++){
                string next = curr + rest[i];
                string remaining = rest.substr(0, i) + rest.substr(i+1);
                permute(next, remaining, res,  n);
            }
        }
    }
    string getPermutation(int n, int k) {
        string s = "";
        for(int i = 1; i<=n; i++){
            s += to_string(i);
        }
        vector<string> res;
        permute("", s, res, n);
        return res[k-1];
    }
};