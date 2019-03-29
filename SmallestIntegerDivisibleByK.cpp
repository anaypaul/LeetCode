class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int val = 0;
        int length = 0;
        for(int i = 0; i<=1000000;i++){
            val = (10 * val + 1) %K;
            length++;
            if(val == 0){
                return length;
            }
        }
        return -1;
    }
};