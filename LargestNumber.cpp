class Solution {
public:
    static bool mycmp(string s1, string s2){
        int i = 0; 
        int j = 0;
        while(i<s1.size() && j<s2.size()){
            if(s1[i] > s2[j]){
                return true;
            }else if(s1[i] < s2[j]){
                return false;
            }else{
                i++;
                j++;
            }
        }
        string t1 = s1 + s2;
        string t2 = s2 + s1;
        if(t1.compare(t2) > 0){
            return true;
        }
        return false;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto x : nums){
            v.push_back(to_string(x));
        }
        sort(v.begin(), v.end(), mycmp);
        string res = "";
        if(v[0][0] == '0'){
            return "0";
        }
        for(auto x : v){
            res += x;
        }
        return res;
    }
};