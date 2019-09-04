class Solution {
public:
    bool leap(int year){
        if(year % 400==0){
            return true;
        }else if(year %100 == 0 ){
            return false;
        }else if(year%4==0){
            return true;
        }
        return false;
    }
    int getDays(int year, int month, int day){
        int cdays=0;
        map<int, int> days = {
            {1, 31},
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
            {12,31}
        };
        if(month==1){
            return day;
        }
        int i;
        for( i = 1;i<month;i++){
            cdays += days[i];
        }
        cdays += day; 
        if(leap(year)){
            if(month>=3){
                cdays++;    
            }
        }
        return cdays;
    }
    int dayOfYear(string date) {
        string year = "";
        string month = "";
        string day = "";
        int c = 0;
        for(int i = 0;i<date.length();i++){
            if(date[i]!='-' && c==0){
                year += date[i];   
            }else if(date[i]!='-' && c==1){
                month += date[i];
            }else if(date[i]!='-' &&c ==2){
                day += date[i];
            }else{
                c++;
            }
        }
        int res = getDays(stoi(year), stoi(month), stoi(day));
        return res;
    }
};