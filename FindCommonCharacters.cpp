class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> answer;
        vector<vector<int>> pre(A.size(), vector<int>(26,0));
        for(int idx = 0 ;idx<A.size();idx++){
            for(int i = 0;i<A[idx].length();i++){
                pre[idx][A[idx][i]-'a']++;
            }
        }
        map<int, string> m;
        char ch = 'a';
        for(int i = 0;i<26;i++){
            string s(1, ch);
            m.insert(make_pair(i, s));
            ch = ch + 1;
        }
        for(int j = 0;j<26;j++){
            int c = INT_MAX;
            for(int i = 0;i<pre.size();i++){
                c = min(c, pre[i][j]); 
            }
            while(c>0){
                answer.push_back(m[j]);
                c--;
            }
        }
        return answer;
        
    }
};