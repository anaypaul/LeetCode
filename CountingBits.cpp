//TIme complexity : O(n * k)
//Space complexity : O(1)
class Solution{
public:
    int getbits(int n){
        int c = 0;
        while(n > 0){
            c++;
            n = n & (n -1);
        }
        return c;
    }
    vector<int> countBits(int num){
        vector<int> res;
        for(int i = 0; i<=num; i++){
            res.push_back(getbits(i));
        }
        return res;
    }
};

//TIme complexiy : O(n)
//Space : O(1)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        int i = 0; 
        int b = 1;
        while(b<= num){
            while(i<b && i+b <= num){
                res[i+b] = res[i] + 1;
                i++;
            }
            i = 0;
            b = b<<1;
        }
        return res;
    }
};