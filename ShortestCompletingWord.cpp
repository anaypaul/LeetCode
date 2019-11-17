class Solution {
public:
    bool isChar(char ch){
        return ( ch>='a' && ch<='z' ) || (ch>='A' && ch<='Z');
    }
    bool check(unordered_map<char,int> um , string s){
        unordered_map<char,int> temp;
        for(int i = 0; i<s.size(); i++){
            temp[tolower(s[i])]++;
        }
        for(auto x : um){
            if(um[x.first] > temp[x.first]){
                return false;
            }
        }
        return true;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char , int> um;
        for(auto x : licensePlate){
            if(isChar(x)){
                um[tolower(x)]++;    
            }
        }
        string res;
        int answer_len = INT_MAX;
        for(int i = 0; i<words.size(); i++){
            if(check(um, words[i]) && words[i].size() < answer_len){
                res = words[i];
                answer_len = words[i].size();
            }
        }
        return res;
    }
};