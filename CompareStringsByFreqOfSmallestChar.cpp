class Solution {
public:
    int f(string s){
        int hash[26] = {0};
        for(int i = 0;i<s.length();i++){
            hash[s[i]-'a']++;
        }
        int res = 0;
        for(int i = 0;i<26;i++){
            if(hash[i]>0){
                res = hash[i];
                break;
            }
        }
        return res;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> result;
        vector<int> word_f;
        for(int i = 0;i<words.size();i++){
            word_f.push_back(f(words[i]));
        }
        vector<int> query_f;
        for(int i = 0;i<queries.size();i++){
            query_f.push_back(f(queries[i]));
        }
        for(int i = 0;i<query_f.size();i++){
            int c = 0;
            for(int j = 0;j<word_f.size();j++){
                if(query_f[i] < word_f[j]){
                    c++;
                }
            }
            result.push_back(c);
        }
        return result;
    }
};