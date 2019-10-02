class Solution {
public:
    bool isSelfDividing(int num){
        int x = num;
        while(num>0){
            int ld = num%10;
            if(ld == 0){
                return false;
            }
            if(x%ld != 0){
                return false;
            }
            num = num/10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i<=right; i++){
            if(isSelfDividing(i)){
                res.push_back(i);
            }
        }
        return res;
    }
};