class Solution {
public:
    int binarytoint(vector<int>& arr){
        int res = 0;
        int i = 0;
        for(int idx = arr.size()-1; idx>=0 ; idx--){
            res = res + arr[idx]*getpower(i);
            i++;
        }
        return res;
    }
    int getpower(int exp){
        if(exp == 0){
            return 1;
        }
        return 2<<(exp-1);
    }
    int findComplement(int num) {
        vector<int> v;
        while(num>0){
            if(num&1){
                v.push_back(0);
            }else{
                v.push_back(1);
            }
            num = num>>1;
        }
        reverse(v.begin(), v.end());
        return binarytoint(v);
        
    }
};