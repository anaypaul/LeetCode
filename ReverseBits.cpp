class Solution {
public:
    uint32_t power(uint32_t base, int exp){
        if(exp == 0){
            return (uint32_t)1;
        }
        if(exp == 1){
            return base;
        }
        uint32_t half = power(base, exp/2);
        if(exp % 2 == 0){
            return half * half;
        }
        return base * half * half;
    }
    uint32_t reverseBits(uint32_t n) {
        cout<<n<<endl;
        vector<uint32_t> v;
        for(int i = 0; i<32; i++){
            v.push_back(n&1);
            n = n >>1;
        }
        uint32_t res = 0;
        reverse(v.begin(), v.end());
        for(int i = 0; i<v.size(); i++){
            res = res + v[i] * power((uint32_t)2, i);
        }
        return res;
    }
};