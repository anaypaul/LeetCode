class Solution {
public:
    bool isPalindrome(int x) {
        if(x <0){
            return false;
        }
        long long int rev = 0;
        int num = x;
        while(num>0){
            rev  = rev *10;
            rev += num%10;
            num = num/10;
        }
        if(x == rev){
            return true;
        }
        return false;
    }
};