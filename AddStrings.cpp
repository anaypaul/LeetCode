class Solution {
public:
    string addStrings(string num1, string num2) {
        unordered_map<char, int> m = {
            {'0', 0},{'1', 1},{'2', 2},{'3', 3},{'4', 4},{'5', 5},{'6', 6},{'7', 7},{'8', 8},{'9', 9},
        };
        unordered_map<int, string> rev_m = {
            {0, "0"},{1, "1"},{2, "2"},{3, "3"},{4, "4"},{5, "5"},{6, "6"},{7, "7"},{8, "8"},{9, "9"},
        };
        string res="";
        int carry = 0;
        int i = num1.size()-1;
        int j = num2.size()-1;
        while(i>=0 && j>=0){
            int x =carry + m[num1[i]] + m[num2[j]];
            carry = x/10;
            x = x%10;
            res =  rev_m[x] +res;
            i--;
            j--;
        }
        while(i>=0){
            int x = carry + m[num1[i]];
            carry = x/10;
            x = x%10;
            res = rev_m[x] + res;
            i--;
        }
        while(j>=0){
            int x = carry + m[num2[j]];
            carry = x/10;
            x = x%10;
            res = rev_m[x] + res;
            j--;
        }
        if(carry!=0){
            res = rev_m[carry] + res;
        }
        return res;
    }
};