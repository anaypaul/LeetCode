//Approach 1 : Recursive solution 
//Time Complexity : O(n^n)
//Space Complexity : O(n^3)
class Solution {
public:
    bool solve(vector<string>& dict, string s, string out, vector<string>& res){
        if(s.size() == 0){
            cout<< out<< endl;
            res.push_back(out);
        }
        for(int i = 1; i<=s.size(); i++){
            string prefix = s.substr(0, i);
            if(out.size() == 0){
                if(find(dict.begin(), dict.end(), prefix) != dict.end() && solve(dict, s.substr(i), out+prefix, res)){
                    return true;
                }
            }else{
                if(find(dict.begin(), dict.end(), prefix) != dict.end() && solve(dict, s.substr(i), out + " "+ prefix, res)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<string> wordBreak(string s, vector<string>& dict) {
        vector<string> res;
        solve(dict, s, "", res);
        return res;
    }
};