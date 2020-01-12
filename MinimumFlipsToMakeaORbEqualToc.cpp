class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<32> num1(a);
        bitset<32> num2(b);
        bitset<32> num3(c);
        int res = 0;
        for(int i = 0; i<32; i++){
            if(num1[i] == 0 && num2[i] == 0 && num3[i] == 1){
                res++;
            }else if(num1[i] == 1 && num2[i] == 1 && num3[i] == 0){
                res += 2;
            }else if(num1[i] == 1 && num2[i] == 0 && num3[i] == 0){
                res++;
            }else if(num1[i] == 0 && num2[i] == 1 && num3[i] == 0){
                res++;
            }
        }
        return res;
    }
};