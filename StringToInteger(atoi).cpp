class Solution {
public:
    int getInt(char ch){
        if(ch == '0'){
            return 0;
        }else if(ch == '1'){
            return 1;
        }else if(ch == '2'){
            return 2;
        }else if(ch == '3'){
            return 3;
        }else if(ch == '4'){
            return 4;
        }else if(ch == '5'){
            return 5;
        }else if(ch == '6'){
            return 6;
        }else if(ch == '7'){
            return 7;
        }else if(ch == '8'){
            return 8;
        }else if(ch == '9'){
            return 9;
        }
        return -1;
    }
    int str2int(string s){
        int sign = 1;
        int i = 0;
        if(s[0] == '-'){
            i++;
            sign = -1;
        }
        else if(s[0] == '+'){
            i++;
            sign = 1;
        }
        long long int res = 0;
        for(; i<s.length() ; i++){
            if(isInt(s[i])){
                res = 10 * res + getInt(s[i]);
            }else{
                break;
            }
            if(res > INT_MAX ){
                break;
            }
        }
        res = res * sign;
        if(INT_MIN >res || INT_MAX < res){
            if(sign == -1){
                return INT_MIN;
            }else{
                return INT_MAX;
            } 
        }
        return (int)res;
    }
    bool isInt(char ch){
        return ch>='0' && ch<='9';
    }
    bool isSign(char ch){
        return ch=='+' || ch=='-';
    }
    int myAtoi(string str) {
        //cleaning the string
        string s = "";
        int i = 0;
        while(str[i] == ' '){
            i++;
        }
        // cout<<"currently at : "<<str[i]<<endl;
        if(!(isInt(str[i]) || isSign(str[i]))){
            return 0;
        }
        for(; i<str.length(); i++){
            if(isSign(str[i]) || isInt(str[i])){
                s = s+str[i];
            }else{
                break;
            }
        }
        
        // cout<<"string : "<<s<<endl;
        int x = str2int(s);
        return x;
    }
};