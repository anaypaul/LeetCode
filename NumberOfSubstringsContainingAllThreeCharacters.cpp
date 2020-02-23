//Approach 1 : TLE
class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        for(int i = 0; i<s.size(); i++){
            unordered_set<char> myset;
            int j = i;
            while(j<s.size()){
                myset.insert(s[j]);
                j++;
                if(myset.size()==3){
                    res += s.size() - j+1;
                    break;
                }
            }
        }
        return res;
    }
};
//Approach 2 : sliding window
class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        vector<int> hash(3, -1);
        for(int i = 0; i<s.size(); i++){
            hash[s[i] - 'a'] = i;
            res += 1 + *min_element(hash.begin(), hash.end());
        }
        return res;
        
    }
};