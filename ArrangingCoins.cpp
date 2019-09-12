class Solution {
public:
    int arrangeCoins(int n) {
        if(n<=1){
            return n;
        }else if(n==3){
            return 2;
        }
        int left = 1;
        int right = (n/2)+1;
        while(left<right){
            unsigned long int mid = left + (right - left)/2;
            unsigned long int x = (mid*(mid + 1))/2;
            if(x <= n){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left-1;
    }
};