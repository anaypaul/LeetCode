class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(s.size() == 0){
            return {};
        }
        vector<string> res;
        for(int i = 0; i<s.size()-1; i++){
            if(s[i] == s[i+1] && s[i] == '+'){
                string temp = s;
                if(s[i] == '+'){
                    temp[i] = temp[i+1] = '-';
                }
                res.push_back(temp);
            }
        }
        return res;
    }
};