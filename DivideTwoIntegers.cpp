static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();
// Timeout solution 
class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0;  
        int sign = 1;
        if(dividend > 0 && divisor > 0){
            if(divisor == 1){
                return dividend;
            }
            int curr = dividend;
            while(curr - divisor >= 0){
                curr = curr - divisor;
                res++;
            }
        }else if(dividend < 0 && divisor > 0){
            if(divisor == 1){
                return dividend;
            }
            sign = -1;
            // dividend = -1 * dividend;
            long int d = -1 * (long)dividend;
            long int curr = d;
            while(curr - divisor >= 0){
                curr = curr - divisor;
                res++;
            }
        }else if(dividend > 0 && divisor < 0){
            sign = -1;
            divisor = -1 * divisor;
            int curr = dividend;
            while(curr - divisor >= 0){
                curr = curr - divisor;
                res++;
            }
        }else if(dividend < 0 && divisor < 0){
            if(dividend == INT_MIN && divisor == -1){
                return INT_MAX;
            }
            sign = 1;
            divisor = abs(divisor);
            long d = (long)dividend;
            long curr = -1 * d;
            while(curr - divisor>=0){
                curr = curr-divisor;
                res++;
            }
        }
        return res* sign;
        
    }
};

// Approach 2

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign= (dividend<0 ^ divisor<0) ? -1 : 1; //same ? 0(false) (XOR)
        
        long ldividend=labs(dividend);
        long ldivisor=labs(divisor);
     
        long res = exp(log(ldividend)-log(ldivisor));
        cout<<ldividend<<"/"<<ldivisor<<"="<<res;
        if(res>INT_MAX)
            return sign==1 ? INT_MAX:INT_MIN;
        return sign*(int)res;
    }
};