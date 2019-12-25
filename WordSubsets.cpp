class Solution {
public:
    bool isSubset(string s, vector<int> BHash){
        vector<int> wordHash(26, 0);
        for(auto x : s){
            wordHash[x-'a']++;
        }
        for(int i = 0; i<26; i++){
            if(BHash[i] > 0){
                if(BHash[i] <= wordHash[i]){
                    continue;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int> BHash(26, 0);
        for(auto x: B){
            vector<int> t(26, 0);
            for(auto y : x){
                t[y-'a']++;
            }
            for(int i = 0; i<26; i++){
                BHash[i] = max(BHash[i], t[i]);
            }
        }
        vector<string> res;
        for(int i = 0; i<A.size(); i++){
            if(isSubset(A[i], BHash)){
                res.push_back(A[i]);
            }
        }
        return res;
    }
};