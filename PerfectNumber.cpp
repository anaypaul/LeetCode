class Solution {
public:
    bool checkPerfectNumber(int num) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(num <=0 ){
            return false;
        }
        int sum = 0;
        for(int i = 1; i*i<=num; i++){
            if(num%i == 0){
                sum += i;
                if(i*i != num){
                    sum += num/i;
                }
            }
        }
        return sum - num == num;
    }
};