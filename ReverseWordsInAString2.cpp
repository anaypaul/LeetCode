class Solution {
public:
    void reverseWords(vector<char>& s) {
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }
        for(int i = 0; i<s.size(); i++){
            int j = i;
            while(j<s.size() && (s[j]!= ' ' || j == s.size()-1)){
                j++;
            }
            j--;
            int low = i;
            int high = j;
            while(low<high){
                char c = s[low];
                s[low] = s[high];
                s[high] = c;
                low++;
                high--;
            }
            i = j+1;
        }
        
    }
};