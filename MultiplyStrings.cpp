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