class Solution {
public:
    void helper(int left, int right, vector<char>& s){
        if(left<=right){
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            helper(left+1,right-1,s);
        }else{
            return;
        }
    }
    void reverseString(vector<char>& s) {
        helper(0,s.size()-1,s);
    }
};