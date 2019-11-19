class Solution {
public:
    string getSign(string s1){
        vector<int> odd(26, 0);
        vector<int> even(26, 0);
        for(int i = 0; i<s1.size(); i++){
            if(i%2== 0){
                even[s1[i]-'a']++;
            }else{
                odd[s1[i]-'a']++;
            }
        }
        string s = "";
        for(int i = 0; i<even.size(); i++){
            s += to_string(even[i]);
        }
        for(int j = 0; j<odd.size(); j++){
            s += to_string(odd[j]);
        }
        return s;
    }
    int numSpecialEquivGroups(vector<string>& A) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_set<string> res;
        for(int i = 0; i<A.size(); i++){
            res.insert(getSign(A[i]));
        }
        return res.size();
    }
};