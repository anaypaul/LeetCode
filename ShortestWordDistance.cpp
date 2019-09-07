class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX;
        map<string, int> m;
        for(int i = 0;i<words.size();i++){
            m[words[i]] = i;
            if(m.find(word1) != m.end() && m.find(word2)!=m.end()){
                cout<<m[word1]<<" "<<m[word2]<<endl;
                res = min(res, abs(m[word1] - m[word2]));
            }
        }
        return res;
        
    }
};