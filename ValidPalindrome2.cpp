class Solution {
public:
    bool check(string s, int low, int high){
        bool res = true;
        while(low<=high){
            if(s[low]!= s[high]){
                return false;
            }
            low++;
            high--;
        }
        return res;
    }
    bool validPalindrome(string s) {
        int low = 0;
        int high = s.size()-1;
        while(low<=high){
            if(s[low]== s[high]){
                low++;
                high--;
            }
            if(s[low]!=s[high]){
                return check(s, low+1, high) || check(s, low, high-1);
            }
        }
        return true;
    }
};