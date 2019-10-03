class Solution {
public:
    string reverseWords(string s) {
        //assuming there are not extra whitespaces. 
        //no white spaces at beginning and end of the string.
        string res = "";
        for(int i = 0;i<s.length(); i++){
            int start = i;
            while(i+1<s.length() && !(s[i+1]== ' ' ||s[i+1]=='\0')){
                i++;
            }
            string t = "";
            for(int j = i ; j>=start; j--){
                t = t + s[j];
            }
            if(res.size()== 0){
                res = res + t;
            }else{
                res = res + ' ' + t;
            }
            i++;
        }
        return res;
    }
};