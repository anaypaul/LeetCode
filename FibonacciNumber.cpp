class Solution {
public:
    int fib(int N) {
        vector<int> fibo(N+1, 0);
        if(N==0){
            return 0;
        }
        fibo[0] = 0;
        fibo[1] = 1;
        for(int i = 2;i<fibo.size();i++){
            fibo[i] = fibo[i-1] + fibo[i-2];
        }
        return fibo[N];
    }
};