class Solution {
public:
    int subtractProductAndSum(int n) {
        long long int sum = 0;
        long long int product = 1;
        while(n > 0){
            int t = n%10;
            sum += t;
            product *= t;
            n = n /10;
        }
        return product - sum;
    }
};