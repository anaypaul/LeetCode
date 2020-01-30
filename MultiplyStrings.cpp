class Solution {
public:
    vector<int> add(vector<int> num1, vector<int> num2){
        int i = num1.size()-1;
        int j = num2.size()-1;
        vector<int> res;
        int carry = 0;
        while(i>=0 && j>=0){
            int sum = num1[i] + num2[j] + carry;
            res.push_back(sum %10);
            carry = sum / 10;
            i--;
            j--;
        }
        while(i>=0){
            int sum = num1[i] + carry;
            res.push_back(sum % 10);
            carry = sum / 10;
            i--;
        }
        while(j>=0){
            int sum = num2[j] + carry;
            res.push_back(sum % 10);
            carry = sum / 10;
            j--;
        }
        if(carry){
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string multiply(string num1, string num2) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int> v1;
        vector<int> v2;
        if(num1[0] == '0' || num2[0] == '0'){
            return "0";
        }
        for(int i = num1.size()-1; i>=0; i--){
            v1.push_back(num1[i]-'0');
        }
        for(int i = num2.size()-1; i>=0; i--){
            v2.push_back(num2[i] - '0');
        }
        vector<int> res;
        for(int i = 0; i<v1.size(); i++){
            vector<int> temp;
            int carry = 0;
            for(int j = 0; j<v2.size(); j++){
                int mul = v1[i] * v2[j] + carry;
                carry = mul /10;
                int val = mul %10;
                temp.push_back(val);
            }
            if(carry){
                temp.push_back(carry);
            }
            reverse(temp.begin(), temp.end());
            int zeros = i;
            while(zeros>0){
                temp.push_back(0);
                zeros--;
            }
            res = add(res, temp);
        }
        string ans = "";        
        for(int i =0; i<res.size(); i++){
            ans += to_string(res[i]);
        }
        return ans;
    }
};

//2nd Implementation
class Solution {
public:
    string add(string s1, string s2){
        string res = "";
        if(s1.size() == 0){
            return s2;
        }
        if(s2.size() == 0){
            return s1;
        }
        if(s1.size() == 0 && s2.size() == 0){
            return "";
        }
        int carry = 0;
        int i = s1.size()-1;
        int j = s2.size()-1;
        while(i>=0 && j>=0){
            int sum = s1[i] - '0' + s2[j] - '0' + carry;
            res += to_string(sum %10);
            carry = sum / 10;
            i--;
            j--;
        }
        while(i>=0){
            int sum = s1[i] - '0' + carry;
            res += to_string(sum % 10);
            carry = sum / 10;
            i--;
        }
        while(j>=0){
            int sum = s2[j] - '0' + carry;
            res += to_string(sum % 10);
            carry = sum / 10;
            j--;
        }
        if(carry){
            res += to_string(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string multiply(string num1, string num2) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int allZero = 0;
        int n = num1.size();
        int m = num2.size();
        int i = n-1;
        int j = m-1;
        int c = 0;
        bool flag = false;
        for(int i = 0; i<num1.size(); i++){
            allZero += num1[i] -'0';
        }
        if(allZero == 0){
            flag = true;
        }
        allZero = 0;
        for(int j = 0; j<num2.size(); j++){
            allZero += num2[j] - '0';
        }
        if(allZero == 0){
            flag = true;
        }
        string res = "";
        if(flag){
            return "0";
        }
        for(i = n-1; i>=0; i--){
            string t = "";
            int carry = 0;
            for(j = m-1; j>=0; j--){
                int sum = (num1[i] - '0') * (num2[j] - '0') + carry;
                t += to_string(sum %10);
                carry = sum / 10;
            }
            if(carry){
                t += to_string(carry);
            }
            reverse(t.begin(), t.end());
            for(int k = 0; k<c; k++){
                t += to_string(0);
            }
            c++;
            res = add(res, t);
        }
        return res;
    }
};