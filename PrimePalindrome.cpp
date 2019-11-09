class Solution {
public:
    int reverse(int n){
        long long int rev = 0;
        long long int num = n;
        while(num > 0){
            rev = rev * 10 + num%10;
            num = num/10;
        }
        if(rev > INT_MAX){
            return -1;
        }
        return (int)rev;
    }
    bool isPrime(int n){
        if(n<2){
            return false;
        }
        for(int i = 2; i<= (int)sqrt(n); i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int primePalindrome(int N) { 
        for(int i = N; i<200000001; i++){
            if(isPrime(i) && i == reverse(i)){
                return i;
            }
            if(10000000 < i && i< 100000000){
                i = 100000000;
            }
        }
        return -1;
    }
};