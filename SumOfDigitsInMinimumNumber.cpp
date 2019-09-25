class Solution {
public:
    int sumOfDigits(vector<int>& a) {
        int num = *min_element(a.begin(), a.end());
        int x = num;
        int sum = 0;
        while(x > 0){
            sum = sum + x %10;
            x = x/10;
        }
        if(sum%2== 1){
            return 0;
        }
        return 1;
    }
};