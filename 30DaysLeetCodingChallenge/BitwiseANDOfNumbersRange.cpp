class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = m;
        while(m < n){
            n = n&(n-1);
        }
        return res & n;
        
    }
};