class Solution {
public:
    bool confusingNumber(int N) {
        unordered_map<int , int > m = {
            {0,0},
            {1,1},
            {6,9},
            {8,8},
            {9,6},
        };
        int newNum = 0;
        int num = N;
        while(num> 0){
            int x = num%10;
            if(m.find(x) == m.end()){
                return false;
            }
            newNum = newNum * 10 + m[x];
            num = num/10;
        }
        if(newNum != N){
            return true;
        }
        return false;
    }
};