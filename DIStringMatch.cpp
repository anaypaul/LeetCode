class Solution {
public:
    vector<int> diStringMatch(string S) {
        int start = 0;
        int end = S.length();
        vector<int> arr;
        
        for(int i =0;i<S.length();i++){
            if(S[i]=='I'){
                arr.push_back(start++);
            }
            if(S[i]=='D'){
                arr.push_back(end--);
            }
        }
        arr.push_back(start++);
        return arr;
        
    }
};