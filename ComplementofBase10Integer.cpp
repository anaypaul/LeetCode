class Solution {
public:
    long long int pow(long long int base, long long int exp){
        if(exp == 0){
            return 1;
        }
        if(exp == 1){
            return base;
        }
        long long int half = pow(base, exp/2);
        if(exp%2 == 0){
            return half * half;
        }
        return base * half * half;
    }
    int bitwiseComplement(int N) {
        if(N == 0){
            return 1;
        }
        vector<int> v;
        while(N>0){
            v.push_back(N&1);
            N = N>>1;
        }
        for(int i = 0; i<v.size(); i++){
            v[i] = v[i] == 1 ? 0 : 1;
        }
        long long int res = 0;
        int k = 0;
        for(int i = 0; i<v.size(); i++){
            res = res + v[i] * pow(2, i);
        }
        return res;
    }
};