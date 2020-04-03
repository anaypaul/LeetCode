class Solution {
public:
    int getSum(int num){
        int res = 0;
        while(num > 0){
            res += (num%10) * (num%10);
            num = num / 10;
        }
        return res;
    }
    bool isHappy(int n) {
        if(n == 1){
            return true;
        }
        unordered_set<int> s;
        s.insert(n);
        while(true){
            int x = getSum(n);
            if(x == 1){
                return true;
            }
            if(s.find(x) != s.end()){
                return false;
            }
            n = x;
            s.insert(x);            
        }
        return true;
    }
};