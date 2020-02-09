class Solution {
public:
    string lastSubstring(string s) {
        int i = 0; 
        int j = 1;
        int k = 0;
        
        while(j + k < s.size()){
            if(s[i+k] < s[j+k]){
                i = max(i + k +1 , j);
                j = i + 1;
                k = 0;
            }
            if(s[i+k] == s[j + k]){
                k++;
            }
            if(s[i+k] > s[j+k]){
                j = j + k + 1;
                k = 0;
            }
        }
        return s.substr(i);
    }
};