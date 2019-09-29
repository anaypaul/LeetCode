class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> um;
        for(auto x : arr){
            um[x] += 1;
        }
        unordered_set<int> s;
        for(auto x : um){
            if(s.find(x.second) == s.end()){
                s.insert(x.second);
            }else{
                return false;
            }
        }
        return true;
    }
};