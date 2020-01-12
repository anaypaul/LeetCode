class Solution {
public:
    bool hasZero(int n){
        while(n>0){
            int d = n %10 ;
            if( d == 0){
                return true;
            }
            n = n/10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res(2);
        for(int i = 1; i<=n-1; i++){
            int x = i;
            int y = n-i;
            if(hasZero(x) == false && hasZero(y) == false){
                return {x,y};
            }
        }
        return {0,0};
    }
};