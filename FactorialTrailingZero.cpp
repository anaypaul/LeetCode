class Solution {
public:
    int trailingZeroes(int n) {
        int zeros = 0;
        int i = 1;
        while(n > 0){
            zeros += n/(int)pow(5,i);
            n = n/(int)pow(5,i);
        }
        return zeros;
    }
};