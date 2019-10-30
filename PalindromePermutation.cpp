class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> um;
        for(auto each : s){
            um[each]++;
        }
        bool res = true;
        if(s.size() %2 == 0){
            for(auto each : um){
                if(each.second % 2  == 0){
                    continue;
                }else{
                    return false;
                }
            }
        }else{
            int twos = 0;
            int ones = 0;
            for(auto each : um){
                if(each.second % 2 == 0){
                    twos++;
                }else if(each.second %2 == 1){
                    ones++;
                }
                if(ones>1){
                    return false;
                }
            }
        }
        return res;
    }
};