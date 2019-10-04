class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int res = 0;
        //can also use unordered_map with custom hashing fucntion to improve constant time access of each characters indices 
        vector<int> hash(26, 0);
        for(int i = 0 ; i<keyboard.size(); i++){
            hash[keyboard[i]-'a'] = i;
        }
        int prev = 0;
        for(auto x : word){
            res += abs(prev - hash[x-'a']);
            prev = hash[x-'a'];
        }
        return res;
    }
};