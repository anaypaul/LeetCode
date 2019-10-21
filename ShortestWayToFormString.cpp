//Approach 1
//Time : O(n log n) using binary search 
class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_map<char, vector<int>> um;
        for(int i = 0; i<source.size(); i++){
            um[source[i]].push_back(i);
        }
        int res = 1;
        if(um.find(target[0]) == um.end()){
            return -1;
        }
        int prev = -1;
        for(int i = 0 ; i < target.size(); i++){
            if(um.find(target[i]) == um.end()){
                return -1;
            }
            auto upper = upper_bound(um[target[i]].begin(), um[target[i]].end(), prev);
            if(upper - um[target[i]].begin() < um[target[i]].size()){
                prev = um[target[i]][upper - um[target[i]].begin()];
            }else{
                res++;
                prev = um[target[i]][0];
            }
        }
        return res;
    }
};