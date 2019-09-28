class Solution {
public:
    string reverseStr(string s, int k) {
        vector<char> v;
        for(auto c: s){
            v.push_back(c);
        }
        for(int i = 0 ; i<s.length(); i = i + 2*k){
            int low = i;
            int high = i + k - 1 < s.length()-1 ? i + k-1 : s.length()-1;
            if(high<s.length()){
                while(low < high){
                    char c = v[low];
                    v[low] = v[high];
                    v[high] = c;
                    low++;
                    high--;
                }
            }
        }
        string res = "";
        for(int i = 0;i<v.size(); i++){
            res += v[i];
        }
        return res;
    }
};