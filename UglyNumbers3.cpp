class Solution {
public:
    int nthUglyNumber(int n, int aa, int bb, int cc) {
        int low = 1; 
        int high = 2 * (int)1e9;
        long a = long(aa);
        long b = long(bb);
        long c = long(cc);
        long ab = (a * b)/__gcd(a, b);
        long ac = (a * c)/__gcd(a, c);
        long bc = (b * c)/__gcd(b, c);
        long abc = (a * bc )/ __gcd(a, bc);
        while(low < high){
            int mid = low + (high - low)/2;
            int count = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc;
            if(count < n){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return low;
    }
};