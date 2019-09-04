class Solution {
public: 
    int countPrimes(int n){
        vector<bool> isPrime(n+1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2;i<=n;i++){
            if(isPrime[i]){
                int j = 2;
                while(i*j<n+1){
                    isPrime[i*j] = false;
                    j++;
                }
            }
        }
        int c = 0;
        for(auto x: isPrime){
            if(x){
                c++;
            }
        }
        return c;
    }
    unsigned long long int fact(int n){
        unsigned long long int res = 1;
        for(unsigned long long int i = 1;i<=n;i++){
            res = res * i;
            res = res %1000000007;
        }
        return res%1000000007;
    }
    int numPrimeArrangements(int n) {
        int x = countPrimes(n);
        cout<<x<<endl;
        cout<<n-x<<endl;
        int res = (fact(x) * fact(n-x))%1000000007;
        return res;
    }
};