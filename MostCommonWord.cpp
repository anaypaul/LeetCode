class Solution {
public:
    bool check(char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
            return true;
        }
        return false;
    }
    string mostCommonWord(string p, vector<string>& banned) {
        set<string> ss;
        for(auto x : banned){
            ss.insert(x);
        }
        
        map<string, int> m;
        string res;
        for(int i = 0;i<p.length(); i++){
            if(check(tolower(p[i]))){
                int j;
                string x = "";
                for(j = i; j<p.length() && check(p[j]) ; j++){
                    char ch = tolower(p[j]);
                    x = x + ch;
                }
                i = j;
                cout<<x<<endl;
                if(m.find(x) == m.end() && ss.find(x) == ss.end()){
                    
                    m.insert(make_pair(x, 1));
                }else if(ss.find(x) == ss.end()){
                    m[x] += 1;
                }
            }
        }
        res = "";
        int count = INT_MIN;
        for(auto& x : m){
            if(count < x.second){
                res = x.first;
                count = x.second;
            }
        }
        return res;
    }
};