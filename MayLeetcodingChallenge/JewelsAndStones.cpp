class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> s;
        for(auto x : J){
            s.insert(x);
        }
        int res = 0;
        for(auto x : S){
            if(s.find(x) != s.end()){
                res++;
            }
        }
        return res;
    }
};