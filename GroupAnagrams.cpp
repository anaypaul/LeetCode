//Approach 1:
// Time Complexity : O(N * KlogK)
// Space Complexity : O(N*K)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for(auto x : strs){
            string t = x;
            sort(t.begin(), t.end());
            m[t].push_back(x);
        }
        for(auto x : m){
            vector<string> t;
            for(auto y : x.second){
                t.push_back(y);
            }
            res.push_back(t);
        }
        return res;
    }
};

//Approach 2: 
//Time Complexity : O(N * K), N = numbet of strings , K = length of the longest string 
//Space Complexity : O(N * K)
class Solution {
public:
    string vec2string(vector<int> hash){
        string res = "";
        for(auto t : hash){
            res += to_string(t) + "#";
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for(auto x : strs){
            vector<int> hash(26, 0);
            for(auto e : x){
                hash[e-'a']++;
            }
            string t = vec2string(hash);
            m[t].push_back(x);
        }
        for(auto x : m){
            vector<string> t;
            for(auto y : x.second){
                t.push_back(y);
            }
            res.push_back(t);
        }
        return res;
    }
};