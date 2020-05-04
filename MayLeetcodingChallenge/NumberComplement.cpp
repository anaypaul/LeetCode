class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int p = 0;
        while(num > 0){
            int bit = num & 1;
            bit = bit == 1 ? 0 : 1;
            res = res + bit * pow(2, p);
            p++;
            num = num >> 1;
        }
        return res;
    }
};