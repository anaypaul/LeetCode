class Solution {
public:
    char getChar(int ch){
        if(ch == 0){
            return '0';
        }else if(ch == 1){
            return '1';
        }else if(ch == 2){
            return '2';
        }else if(ch == 3){
            return '3';
        }else if(ch == 4){
            return '4';
        }else if(ch == 5){
            return '5';
        }else if(ch == 6){
            return '6';
        }else if(ch == 7){
            return '7';
        }else if(ch == 8){
            return '8';
        }else if(ch == 9){
            return '9';
        }
        return -1;
    }
    string countAndSay(int n) {
        string s = "1";
        for(int i = 2; i<=n; i++){
            string temp = "";
            char curr = s[0];
            int c = 0;
            for(int j = 0; j<s.length(); j++){
                if(s[j] == curr){
                    c++;
                }else if(s[j] != curr){
                    temp = temp + getChar(c) + curr;
                    c = 1;
                    curr = s[j];
                }
                if(j == s.length()-1){
                    temp = temp + getChar(c) + curr;
                    break;
                }
            }
            s = temp;
        }
        return s;
    }
};