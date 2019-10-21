class Solution {
public:
    double cal(double base, long long int exp){
        if(exp == 0){
            return 1.0;
        }
        double half = cal(base, exp/2);
        if(exp%2 == 0 ){
            return half * half;
        }else{
            return half * half * base;
        }
    }
    double myPow(double x, int n) {
        long long int exp; 
        if(n < 0){
            exp = (long long int)-1 * n;
        }else{
            exp = n;
        }
        if(n==0){
            return (double)1;
        }
        double value = cal(x, exp);
        if(n<0){
            return (double)1.0/value;
        }
        return value;
    }
};