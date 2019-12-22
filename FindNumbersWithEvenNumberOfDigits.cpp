class Solution {
public:
    int count(int num){
        int c = 0;
        while(num>0){
            c++;
            num = num/10;
        }
        return c;
    }
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(auto x : nums){
            if(count(x)%2==0){
                res++;
            }
        }
        return res;
    }
};