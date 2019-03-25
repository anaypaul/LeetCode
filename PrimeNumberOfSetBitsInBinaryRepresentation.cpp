vector<bool> isPrime(65, true);
class Solution {
public:
    static int countBits(int num){
        int res = 0;
        while(num>0){
            if(num&1==1){
                res++;
            }
            num = num>>1;
        }
        return res;
    }
    int countPrimeSetBits(int L, int R) {
        int l = 0;
        int x = R;
        while(x>0){
            l++;
            x=x>>1;
        }
        cout<<R<<endl;
        
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i=2;i<isPrime.size();i++){
            if(isPrime[i]){
                int j = 2;
                while(i*j<isPrime.size()){
                    isPrime[i*j] = false;
                    j++;
                }
            }
        }
        int ans =0;
        for(int i = L;i<=R;i++){
            if(isPrime[countBits(i)]){
                ans++;
            }
        }        
        return ans;
    }
};