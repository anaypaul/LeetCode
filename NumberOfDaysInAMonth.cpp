class Solution {
public:
    bool checkLeap(int Y){
        if(Y%400 == 0){
            return true;
        }else if(Y%100==0){
            return false;
        }else if(Y%4 ==0){
            return true;
        }
        return false;
    }
    int getDays(int Y, int M){
        map<int,int> days = {
            {1,31},
            {2,28},
            {3,31},
            {4,30},
            {5,31},
            {6,30},
            {7,31},
            {8,31},
            {9,30},
            {10,31},
            {11,30},
            {12,31},
        };
        int ans = days[M];
        if(checkLeap(Y) && M == 2){
            ans++;
        }
        return ans;
    }
    int numberOfDays(int Y, int M) {
        return getDays(Y,M);
    }
};