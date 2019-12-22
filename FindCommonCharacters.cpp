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

//Approach 2
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<string> res;
        int n = A.size();
        int hash[n][26];
        memset(hash, 0, sizeof(hash));
        int idx = 0;
        for(auto each : A){
            for(auto x : each){
                hash[idx][x-'a']++;
            }
            idx++;
        }
        for(int j = 0; j<26; j++){
            int minCount = INT_MAX;
            bool hashZero = false;
            for(int i = 0; i<n; i++){
                if(hash[i][j]>0){
                    minCount = min(minCount, hash[i][j]);
                }
                if(hash[i][j] == 0){
                    hashZero = true;
                    break;
                }
            }
            if(minCount!=INT_MAX && hashZero == false){
                char c = (char)('a' + j);
                string temp(1, c);
                while(minCount){
                    res.push_back(temp);
                    minCount--;
                }
            }
        }
        return res;
    }
};