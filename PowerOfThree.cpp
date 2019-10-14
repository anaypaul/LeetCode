//Approach 1
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1){
            return false;
        }
        while(n%3 ==0){
            n = n / 3;
        }
        return n == 1;
    }
};

//Approach 2
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0){
            return false;
        }
        return pow(3,round(log(n)/log(3)))==n;
    }
};