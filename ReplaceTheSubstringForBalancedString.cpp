class Solution {
public:
    int balancedString(string s) {
        int c = s.size()/4;
        vector<char> v;
        v.push_back('Q');v.push_back('W');v.push_back('E');v.push_back('R');
        unordered_map<char, int> um;
        for(auto x : v){
            um[x] = 0;
        }
        for(int i = 0; i<s.length(); i++){
            um[s[i]] += 1;
        }
        if(c == um['Q'] && c == um['W'] && c == um['E'] && c == um['R']){
            return 0;
        }
        int i = 0; 
        int j = 0;
        int res = INT_MAX;
        while(j< s.length()){
            um[s[j]]--;
            j++;
            while(i<j && um['W'] <= c && um['Q'] <=c && um['E']<=c && um['R']<=c){
                res = min(j-i, res);
                um[s[i]]++;
                i++;
            }
        }
        return res;
    }
};