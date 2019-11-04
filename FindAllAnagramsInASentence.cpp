//Approach 1: O(n^2)
//check for anagram for all substrings.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hash(26,0);
        for(auto x : p){
            hash[x-'a']++;
        }
        vector<int> res;
        if(s.size() == 0 ||s.size() < p.size()){
            return res;
        }
        int k = p.size();
        for(int i = 0; i<=s.size()-k; i++){
            cout<<"i : "<<i<<endl;
            string t = s.substr(i, k);
            // cout<<t<<endl;
            vector<int> temp_hash(26,0);
            for(auto x : t){
                temp_hash[x-'a']++;
            }
            bool flag = true;
            for(int i = 0; i<hash.size(); i++){
                if(hash[i] != temp_hash[i]){
                    flag = false;
                    break;
                }
            }
            temp_hash.clear();
            if(flag){
                res.push_back(i);
            }
            cout<<endl;
        }
        return res;
    }
};

//Approach 2
//O(n) using sliding window
class Solution {
public:
    bool check(vector<int> hashS, vector<int> hashP){
        for(int i = 0; i<26 ; i++){
            if(hashS[i] != hashP[i]){
                return false;
            }    
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> hashP(26, 0);
        vector<int> hashS(26, 0);
        vector<int> res;
        if(s.size() == 0 || s.size() < p.size()){
            return res;
        }
        for(auto x : p){
            hashP[x-'a']++;
        }
        int k = p.size();
        int n = s.size();
        for(int i = 0; i<k;i++){
            hashS[s[i]-'a']++;
        }
        if(check(hashS, hashP)){
            res.push_back(0);
        }
        for(int i = 1; i<=n-k; i++ ){
            hashS[s[i-1] - 'a']--;
            hashS[s[i+k-1] - 'a']++;
            if(check(hashS, hashP)){
                res.push_back(i);
            }
        }
        return res;
    }
};