class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevbit = n & 1;
        while(n > 0){
            n = n>>1;
            int curr = n&1;
            if(curr == prevbit){
                return false;
            }
            prevbit = curr;
        }
        return true;
    }
};