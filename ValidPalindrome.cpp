class Solution {
public:
    bool check(char ch){
        return tolower(ch)<='z' && tolower(ch)>='a' || ('0'<=ch && ch<='9');
    }
    bool isPalindrome(string s) {
        int low = 0;
        int high = s.length()-1;
        while(low<high){
            if(check(s[low]) && check(s[high])){
                if(tolower(s[low]) == tolower(s[high])){
                    low++;
                    high--;
                }else{
                    return false;
                }
            }else{
                if(!check(s[low])){
                    low++;
                }else{
                    high--;
                }
            }
        }
        return true;
    }
};