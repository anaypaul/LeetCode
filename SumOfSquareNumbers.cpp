class Solution {
public:
    bool judgeSquareSum(int c) {
        int x = (int)sqrt(c);
        unordered_set<int> s;
        for(int i = 0; i<=x;i++){
            s.insert(i*i);
            if(s.find(c-(i*i)) != s.end()){
                return true;
            }
        }
        return false;
    }
};