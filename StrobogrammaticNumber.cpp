class Solution {
public:
    bool check(char a , char b){
        if(a=='1' && b==a){
            return true;
        }else if(a=='8' && b==a){
            return true;
        }else if((a=='6' && b=='9') || (b=='6' && a=='9')){
            return true;
        }else if(a=='0' && b==a){
            return true;
        }
        return false;
    }
    bool isStrobogrammatic(string num) {
        int l = 0;
        int r = num.length()-1;
        bool ans = true;
        while(l<r){
            if(!check(num[l], num[r])){
                return false;
            }
            l++;
            r--;
        }
        if(num.length()%2==1){
            if(!(num[l] == '1' || num[l] == '0' || num[l] == '8')){
                return false;
            }
        }
        return true;
    }
};