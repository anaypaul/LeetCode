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
// Approach 2
class Solution {
public:
    bool isPrime(int n){
        for(int i = 2; i*i<=n; i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int genPalindrome(int num){
        string s = to_string(num);
        string temp = s;
        reverse(temp.begin(), temp.end());
        s.pop_back();
        return stoi(s + temp);
    }
    int primePalindrome(int N) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int res = -1;
        if(N<=2){
            res = 2;
        }else if(N>=8 && N<=11){
            res = 11;
        }else{
            for(int i = 1; i<1000000; i++){
                int temp = genPalindrome(i);
                if(temp >= N && isPrime(temp)){
                    res = temp;
                    break;
                }
            }
        }
        return res;
    }
};