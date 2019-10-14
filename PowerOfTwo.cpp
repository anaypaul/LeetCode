//Approach 1
//shifting 1's position bit by bit and comparing with the given number to check 
//for power of 2.
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0){
            return false;
        }
        if(n == 1){
            return true;
        }
        for(int i = 1; i<=31; i++){
            if(n == (1<<i)){
                return true;
            }
        }
        return false;
    }
};